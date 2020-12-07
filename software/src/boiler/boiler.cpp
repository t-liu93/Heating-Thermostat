#include "boiler.h"
#include <ESP8266WiFi.h>
#include "communication/mqtt.h"

constexpr char STATE_TOPIC[] = "switch/boiler/state";
constexpr char COMMAND_TOPIC[] = "switch/boiler/command";
constexpr char PAYLOAD_ON[] = "on";
constexpr char PAYLOAD_OFF[] = "off";

constexpr uint8_t PIN_HEATER = 14;

volatile int Boiler::dutyCycle = 0;
volatile uint8_t Boiler::status = 0;
volatile uint8_t Boiler::pinHeater = PIN_HEATER;


void Boiler::on()
{
    dutyCycle = 5;
    digitalWrite(Boiler::pinHeater, 1);
    status = 1;
    MQTT::client.publish(STATE_TOPIC, PAYLOAD_ON);
}

void Boiler::off()
{
    dutyCycle = 0;
    digitalWrite(Boiler::pinHeater, 0);
    status = 0;
    MQTT::client.publish(STATE_TOPIC, PAYLOAD_OFF);
}

Boiler::Boiler()
{

}