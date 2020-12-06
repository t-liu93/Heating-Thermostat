#include "boiler.h"

volatile int Boiler::dutyCycle = 0;
volatile uint8_t Boiler::status = 0;

Boiler::Boiler()
{

}