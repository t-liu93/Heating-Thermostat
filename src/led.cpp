#include "led.h"

static unsigned long prv_millisec = 0;
static const long interval_ten_seconds = 10000;
static const long interval_one_second = 1000;
static const long interval_two_hundred_milliseconds = 200;

static void toggle_led(uint8_t pin)
{
    int pin_states = digitalRead(pin);
    pin_states = (pin_states == HIGH)? LOW : HIGH;
    digitalWrite(pin, pin_states);
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