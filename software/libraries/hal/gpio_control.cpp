#include <Esp.h>
#include "gpio_control.h"
#include "helper.h"

#define BUILDIN_LED_ON    (LOW)
#define BUILDIN_LED_OFF   (HIGH)
#define BOILER_ON         (HIGH)
#define BOILER_OFF        (LOW)

#define RELAY_PIN         (14)
#define BUILD_IN_LED_RED  (0)
#define BUILD_IN_LED_BLUE (2)

static unsigned long prv_millisec                   = 0;
static const long interval_ten_seconds              = 10000;
static const long interval_one_second               = 1000;
static const long interval_two_hundred_milliseconds = 200;

static void toggle_led(uint8_t pin)
{
    int pin_states = digitalRead(pin);
    pin_states = (pin_states == HIGH)? LOW : HIGH;
    digitalWrite(pin, pin_states);
}

void pin_initialization()
{
    pinMode(BUILD_IN_LED_BLUE, OUTPUT);
    digitalWrite(BUILD_IN_LED_BLUE, BUILDIN_LED_OFF);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, BOILER_OFF);
}

void restart_chip()
{
    DEBUG_PRINT("Restarting...");
    ESP.restart();
}

void normal_led_blinking(uint8_t pin, unsigned long cur_milli)
{
    if (cur_milli - prv_millisec >= interval_ten_seconds)
    {
        prv_millisec = cur_milli;

        digitalWrite(pin, BUILDIN_LED_ON);
    }

    if (cur_milli - prv_millisec >= interval_two_hundred_milliseconds)
    {
        digitalWrite(pin, BUILDIN_LED_OFF);
    }
}

void one_second_led_blinking(uint8_t pin, unsigned long cur_milli)
{
    if (cur_milli - prv_millisec >= interval_one_second)
    {
        prv_millisec = cur_milli;

        toggle_led(pin);
    }
}

void boiler_on()
{
    digitalWrite(RELAY_PIN, BOILER_ON);
}

void boiler_off()
{
    digitalWrite(RELAY_PIN, BOILER_OFF);
}