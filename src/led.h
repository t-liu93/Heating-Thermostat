#ifndef __SRC_LED_H
#define __SRC_LED_H

#include <Arduino.h>

#define BUILDIN_LED_ON (LOW)
#define BUILDIN_LED_OFF (HIGH)

// Normal led blinking every 10 seconds, each blink takes 200ms
void normal_led_blinking(uint8_t pin, unsigned long cur_milli);

// Led blinking every second, each blink takes one second.
void one_second_led_blinking(uint8_t pin, unsigned long cur_milli);

#endif