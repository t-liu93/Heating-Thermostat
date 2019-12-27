#ifndef __LIBRARIES_HAL_GPIO_H
#define __LIBRARIES_HAL_GPIO_H

#include <Arduino.h>

/**
 * General methods
 */
void pin_initialization();

void restart_chip();

/**
 * LED control
 */
// Normal led blinking every 10 seconds, each blink takes 200ms
void normal_led_blinking(uint8_t pin, unsigned long cur_milli);

// Led blinking every second, each blink takes one second.
void one_second_led_blinking(uint8_t pin, unsigned long cur_milli);

/**
 * Boiler relay control
 */
void boiler_on();

void boiler_off();

#endif