#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "communication.h"
#include "hw_control.h"
#include "helper.h"

#define WIFI_SSID ("Home")
#define WIFI_PASSWORD ("ireallydontknow")

#define MQTT_BROKER_IP ("10.238.75.62")
#define MQTT_BROKER_PORT (1883)

#define MQTT_NAME ("ESP8266 Boiler")
#define MQTT_UNAME ("mqtt")
#define MQTT_PAS ("mqtt")

#define BOILER_MQTT_STATE_TOPIC ("switch/boiler/state")
#define BOILER_MQTT_COMMAND_TOPIC ("switch/boiler/command")
#define BOILER_MQTT_PAYLOAD_ON ("on")
#define BOILER_MQTT_PAYLOAD_OFF ("off")

static const String boiler_mqtt_state_topic = BOILER_MQTT_STATE_TOPIC;
static const String boiler_mqtt_command_topic = BOILER_MQTT_COMMAND_TOPIC;
static const String boiler_mqtt_payload_on = BOILER_MQTT_PAYLOAD_ON;
static const String boiler_mqtt_payload_off = BOILER_MQTT_PAYLOAD_OFF;

static WiFiClient espClient;
static PubSubClient client(espClient);

static void mqtt_cb(char* topic, byte* payload, unsigned int length)
{
    DEBUG_PRINT(topic);
    DEBUG_PRINT("\n");
    DEBUG_PRINT((char*)payload);
    DEBUG_PRINT("\n");
    DEBUG_PRINT(length);
    DEBUG_PRINT("\n");

    if (boiler_mqtt_command_topic.equals(topic))
    {

        if (memcmp(payload, BOILER_MQTT_PAYLOAD_ON, length) == 0)
        {
            boiler_on();
            client.publish(BOILER_MQTT_STATE_TOPIC, BOILER_MQTT_PAYLOAD_ON);
        }
        else
        {
            boiler_off();
            client.publish(BOILER_MQTT_STATE_TOPIC, BOILER_MQTT_PAYLOAD_OFF);
        }
    }

}

void wifi_initialization()
{
    Serial.begin(115200);
    DEBUG_PRINTLN();

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    DEBUG_PRINT("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        DEBUG_PRINT(".");
    }
    Serial.println();

    DEBUG_PRINT("Connected, IP address: ");
    DEBUG_PRINTLN(WiFi.localIP());
}

bool wifi_is_connected()
{
    return (WiFi.status() == WL_CONNECTED);
}

void mqtt_initialization()
{
    client.setServer(MQTT_BROKER_IP, MQTT_BROKER_PORT);

    DEBUG_PRINT("Connecting to broker..");

    if (client.connect(MQTT_NAME, MQTT_UNAME, MQTT_PAS))
    {
        DEBUG_PRINT("Connection successful.\n");

        client.publish(BOILER_MQTT_STATE_TOPIC, BOILER_MQTT_PAYLOAD_OFF);
        DEBUG_PRINT("Subscribing..");

        if (client.subscribe(BOILER_MQTT_COMMAND_TOPIC))
        {
            DEBUG_PRINT("Subscribe successful.\n");
            client.setCallback(mqtt_cb);
        }
        else
        {
            DEBUG_PRINT("Subscribing failed. \n");
            restart_chip();
        }
    }
    else
    {
        DEBUG_PRINT("Connection failed.\n");
        restart_chip();
    }
}

void mqtt_poll()
{
    client.loop();
}