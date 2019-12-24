#include "src/support/wifi/wireless.h"
#include <PubSubClient.h>
#include <math.h>

WiFiClient espClient;
PubSubClient client(espClient);

#define FLOAT_DIGITS (5)

static float byte_to_float(byte* bytes)
{
    float retval = 0;
    char value[FLOAT_DIGITS];
    memcpy(value, bytes, 5);
    int16_t dot_place = 0;
    for (uint32_t i = 0; i < FLOAT_DIGITS; ++i)
    {
        if (value[i] == 46)
        {
            dot_place = i;
        }
    }

    for (int32_t i = 0; i < FLOAT_DIGITS; ++i)
    {
        float dig = 0;
        if (i != dot_place)
        {
            int exp = (i < dot_place)? (dot_place - i - 1) : (dot_place - i);
            dig = (value[i] == 0)? (0) : ((value[i] - 48) * (powf(10, exp)));
            retval += dig;
        }
    }

    return retval;
}

static void callback(char* topic, byte* payload, unsigned int length)
{
    Serial.print(topic);
    Serial.print("\n");
    Serial.print((char*)payload);
    Serial.print("\n");
    // if (memcmp(topic, "switch/boiler/state", 19) == 0)
    // {
    //     Serial.print("convert\n");
    //     float temp = byte_to_float(payload);
    //     Serial.print(temp);
    // }
    if (memcmp(payload, "on", 2) == 0)
    {
        digitalWrite(16, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        client.publish("switch/boiler/state", "on");
    }
    else
    {
        digitalWrite(16, LOW);
        digitalWrite(LED_BUILTIN, HIGH);
        client.publish("switch/boiler/state", "off");
    }
    memset(payload, 0, 16);
}
void setup()
{
    wifi_initialization();

    /**
     * Following tests
     */
    client.setServer("10.238.75.62", 1883);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(16, OUTPUT);
    digitalWrite(16, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
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
    client.publish("switch/boiler/state", "off");
    Serial.print("Subscribing..");
    result = client.subscribe("switch/boiler/command");

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
