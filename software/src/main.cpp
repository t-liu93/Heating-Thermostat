#include <Arduino.h>
#include <WifiManager.h>
#include <TaskScheduler.h>

#include "esp8266ota.h"
#include "boiler/boiler.h"
#include "communication/mqtt.h"

constexpr uint8_t PIN_STATUS = 12;
constexpr uint8_t PIN_TOGGLE = 13;

constexpr uint32_t PWM_TICKS = 5000;
constexpr int debounceDelay = 20;

volatile int state = 0;
volatile int buttonState = 0;
volatile long lastDebounceTime;

WiFiManager *wifiManager = nullptr;
Esp8266OTA *updater = nullptr;
Scheduler *ts;
Task *updaterTask;
Task *mqttTask;
Task *mqttCheckConnectionTask;
Task *pidTask;

void WifiInitialization();
void updaterTick();
void mqttTick();
void mqttCheckConnectionTick();
void pidTick();

void ICACHE_RAM_ATTR pwmStatusLight()
{
    uint32_t nextTime = PWM_TICKS;
    if (Boiler::dutyCycle == 0)
    {
        state = 0;
        digitalWrite(PIN_STATUS, state);
        timer1_write(PWM_TICKS);
        return;
    }
    if (Boiler::dutyCycle == 100)
    {
        state = 1;
        digitalWrite(PIN_STATUS, state);
        timer1_write(PWM_TICKS);
        return;
    }
    if (state == 1)
    {
        nextTime = (PWM_TICKS / 100 * (100 - Boiler::dutyCycle));
        state = 0;
    }
    else
    {
        nextTime = (PWM_TICKS / 100 * (Boiler::dutyCycle));
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
    if (Boiler::status == 0)
    {
        Boiler::on();
    }
    else
    {
        Boiler::off();
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(Boiler::pinHeater, OUTPUT);
    pinMode(PIN_STATUS, OUTPUT);
    digitalWrite(Boiler::pinHeater, 0);
    digitalWrite(PIN_STATUS, 0);
    timer1_attachInterrupt(&pwmStatusLight);
    timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
    timer1_write(PWM_TICKS);
    attachInterrupt(digitalPinToInterrupt(PIN_TOGGLE), &buttonISR, CHANGE);

    WifiInitialization();
    updater = new Esp8266OTA("esp", "password");
    ts = new Scheduler();
    updaterTask = new Task(TASK_MILLISECOND, TASK_FOREVER, updaterTick, ts, true, nullptr, nullptr);
    mqttTask = new Task(TASK_MILLISECOND, TASK_FOREVER, mqttTick, ts, true, nullptr, nullptr);
    mqttCheckConnectionTask = new Task(TASK_MINUTE, TASK_FOREVER, mqttCheckConnectionTick, ts, true, nullptr, nullptr);
    pidTask = new Task(10 * TASK_MINUTE, TASK_FOREVER, pidTick, ts, true, nullptr, nullptr);
    MQTT::connect();
}
void loop()
{
    ts->execute();
}

void pidTick()
{

}

void mqttCheckConnectionTick()
{
    MQTT::checkConnection();
}

void mqttTick()
{
    MQTT::client.loop();
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