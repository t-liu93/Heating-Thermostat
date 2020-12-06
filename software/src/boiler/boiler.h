#pragma once

#include <Arduino.h>

class Boiler
{
public:
    Boiler();
    static volatile int dutyCycle;
    static volatile uint8_t status;
};