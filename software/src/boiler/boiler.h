#pragma once

#include <Arduino.h>

class Boiler
{
public:
    static volatile int dutyCycle;
    static volatile uint8_t status;
    static volatile uint8_t pinHeater;

    static void on();
    static void off();

private:
    Boiler();
};