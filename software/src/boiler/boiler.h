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
    static void tick();

    static volatile float kP;
    static volatile float kI;
    static volatile float kD;
    static volatile float setPoint;
    static volatile bool setState;
    static volatile float actualTemp;
    static volatile float err;
    static volatile float lastErr;
    static volatile float intergal;
private:
    Boiler();
};