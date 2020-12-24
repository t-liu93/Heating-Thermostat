#include "boiler.h"
#include <ESP8266WiFi.h>
#include "communication/mqtt.h"

constexpr char STATE_TOPIC[] = "switch/boiler/state";
constexpr char COMMAND_TOPIC[] = "switch/boiler/command";
constexpr char PAYLOAD_ON[] = "on";
constexpr char PAYLOAD_OFF[] = "off";

constexpr uint8_t PIN_HEATER = 14;
constexpr float INTERGAL_MAX = 10;
constexpr float INTERGAL_DEAD = 0.5;

volatile int Boiler::dutyCycle = 0;
volatile uint8_t Boiler::status = 0;
volatile uint8_t Boiler::pinHeater = PIN_HEATER;
volatile float Boiler::kP = 0.2f;
volatile float Boiler::kI = 0.1f;
volatile float Boiler::kD = 0.5f;
volatile float Boiler::setPoint = 0.0f;
volatile bool Boiler::setState = false;
volatile float Boiler::actualTemp = 0.0f;
volatile float Boiler::err = 0.0f;
volatile float Boiler::lastErr = 0.0f;
volatile float Boiler::intergal = 0.0f;


void Boiler::on()
{
    dutyCycle = 5;
    digitalWrite(Boiler::pinHeater, 1);
    status = 1;
    MQTT::client.publish(STATE_TOPIC, PAYLOAD_ON);
    // MQTT::client.publish(COMMAND_TOPIC, PAYLOAD_ON);
}

void Boiler::off()
{
    dutyCycle = 0;
    digitalWrite(Boiler::pinHeater, 0);
    status = 0;
    MQTT::client.publish(STATE_TOPIC, PAYLOAD_OFF);
    // MQTT::client.publish(COMMAND_TOPIC, PAYLOAD_OFF);
}

void Boiler::tick()
{
    Boiler::err = Boiler::actualTemp - Boiler::setPoint;
    Boiler::intergal += Boiler::err;
    if (std::abs(Boiler::intergal >= INTERGAL_MAX)) Boiler::intergal = (Boiler::intergal >= 0)? INTERGAL_MAX : -INTERGAL_MAX;
    if (std::abs(Boiler::err) <= INTERGAL_DEAD) Boiler::intergal = 0;
    float output = (Boiler::kP * Boiler::err + Boiler::kD * (Boiler::err - Boiler::lastErr) + Boiler::kI * Boiler::intergal);
    Boiler::lastErr = Boiler::err;
    Boiler::setState = (output >= 0.25)? true : false;

    // if (Boiler::setState) Boiler::on();
    // else Boiler::off();
}

Boiler::Boiler()
{

}