#include <ESP8266WiFi.h>
#include "mqtt.h"
#include "boiler/boiler.h"

constexpr char STATE_TOPIC[] = "switch/boiler/state";
constexpr char COMMAND_TOPIC[] = "switch/boiler/command";
constexpr char PAYLOAD_ON[] = "on";
constexpr char PAYLOAD_OFF[] = "off";

WiFiClient MQTT::wifiClient = WiFiClient();
PubSubClient MQTT::client = PubSubClient(MQTT::wifiClient);

String MQTT::ip = "";
uint16_t MQTT::port = 1883;
String MQTT::uName = "";
String MQTT::pass = "";

void MQTT::mqtt_cb(char* topic, byte* payload, unsigned int length)
{
    if (String(COMMAND_TOPIC).equals(topic))
    {

        if (memcmp(payload, PAYLOAD_ON, length) == 0)
        {
            Boiler::on();
        }
        else
        {
            Boiler::off();
        }
    }
}

void MQTT::checkConnection()
{
    if (! MQTT::client.connected()) MQTT::connect();
}

void MQTT::connect(String brokerIp, uint16_t brokerPort, String brokerUserName, String brokerPass)
{
    MQTT::ip = brokerIp;
    MQTT::port = brokerPort;
    MQTT::uName = brokerUserName;
    MQTT::pass = brokerPass;
    MQTT::client.setServer(MQTT::ip.c_str(), MQTT::port);
    if (MQTT::client.connect("Heating Thermostat", MQTT::uName.c_str(), MQTT::pass.c_str()))
    {
        client.publish(STATE_TOPIC, PAYLOAD_OFF);

        if (client.subscribe(COMMAND_TOPIC))
        {
            client.setCallback(mqtt_cb);
        }
        else
        {
            ESP.restart();
        }
    }
    else
    {
        ESP.restart();
    }

}
