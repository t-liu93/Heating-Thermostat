#include "src/support/wifi/wireless.h"
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

static void callback(const char* topic, byte* payload, unsigned int length)
{
    Serial.print(topic);
    Serial.print("\n");
    Serial.print((char*)payload);
    Serial.print("\n");
    memset(payload, 0, 4);
}
void setup()
{
    wifi_initialization();

    /**
     * Following tests
     */
    client.setServer("10.238.75.64", 1883);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.print("Connecting to broker..");
    bool result = client.connect("ESP8266 boiler", "mqtt", "mqtt");
    if (result)
    {
        Serial.print("Connection successful.\n");
    }
    else
    {
        Serial.print("Connection failed.\n");
    }
    Serial.print("Subscribing..");
    result = client.subscribe("boiler/command");

    if (result)
    {
        Serial.print("Subscribe successful.\n");
    }
    else
    {
        Serial.print("Subscribe failed.\n");
    }
    client.setCallback(callback);
    // if (result)
    // {
    //     Serial.print("Callback set successful.\n");
    // }
    // else
    // {
    //     Serial.print("Callback set failed.\n");
    // }
}

void loop()
{
    bool result = client.loop();
    // if (result)
    // {
    //     Serial.print("Subscribe successful.\n");
    // }
    // else
    // {
    //     Serial.print("Subscribe failed.\n");
    // }
}
