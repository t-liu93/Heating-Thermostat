#include <Arduino.h>
#include <WifiManager.h>
#include <TaskScheduler.h>

#include "esp8266ota.h"

constexpr uint8_t PIN_HEATER = 14;
constexpr uint8_t PIN_TOGGLE = 13;
constexpr uint8_t PIN_STATUS = 12;

constexpr uint32_t PWM_TICKS = 5000;

volatile int dutyCycle = 0;
volatile int state = 0;
volatile uint8_t status = 0;
volatile int buttonState = 0;
volatile long lastDebounceTime;

constexpr int debounceDelay = 20;

WiFiManager *wifiManager = nullptr;
Esp8266OTA *updater = nullptr;
Scheduler *ts;
Task *updaterTask;

void WifiInitialization();
void updaterTick();

void ICACHE_RAM_ATTR pwmStatusLight()
{
    uint32_t nextTime = PWM_TICKS;
    if (dutyCycle == 0)
    {
        state = 0;
        digitalWrite(PIN_STATUS, state);
        timer1_write(PWM_TICKS);
        return;
    }
    if (dutyCycle == 100)
    {
        state = 1;
        digitalWrite(PIN_STATUS, state);
        timer1_write(PWM_TICKS);
        return;
    }
    if (state == 1)
    {
        nextTime = (PWM_TICKS / 100 * (100 - dutyCycle));
        state = 0;
    }
    else
    {
        nextTime = (PWM_TICKS / 100 * (dutyCycle));
        state = 1;
    }
    digitalWrite(PIN_STATUS, state);
    timer1_write(nextTime);
}

void ICACHE_RAM_ATTR buttonISR()
{
    int reading = digitalRead(PIN_TOGGLE);
    if (reading == buttonState) return;
    bool debounce = false;

    if ((millis() - lastDebounceTime) <= debounceDelay)
    {
        debounce = true;
    }

    lastDebounceTime = millis();

    if (debounce) return;
    buttonState = reading;

    if (reading == 0) return;
    if (status == 0)
    {
        digitalWrite(PIN_HEATER, 1);
        dutyCycle = 5;
        status = 1;
    }
    else
    {
        digitalWrite(PIN_HEATER, 0);
        dutyCycle = 0;
        status = 0;
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(PIN_HEATER, OUTPUT);
    pinMode(PIN_STATUS, OUTPUT);
    digitalWrite(PIN_HEATER, 0);
    digitalWrite(PIN_STATUS, 0);
    timer1_attachInterrupt(&pwmStatusLight);
    timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
    timer1_write(PWM_TICKS);
    attachInterrupt(digitalPinToInterrupt(PIN_TOGGLE), &buttonISR, CHANGE);

    WifiInitialization();
    updater = new Esp8266OTA("esp", "password");
    ts = new Scheduler();
    updaterTask = new Task(TASK_MILLISECOND, TASK_FOREVER, updaterTick, ts, true, nullptr, nullptr);
}
void loop()
{
    ts->execute();
}

void updaterTick()
{
    updater->handle();
}

void WifiInitialization()
{
    wifiManager = new WiFiManager();
    wifiManager->autoConnect("EspAp", "12345678");
    WiFi.hostname("Boiler");
}