#include "mqtt.h"

constexpr char STATE_TOPIC[] = "switch/boiler/state";
constexpr char COMMAND_TOPIC[] = "switch/boiler/command";

void MQTT::mqtt_cb(char* topic, byte* payload, unsigned int length)
{
    // if (boiler_mqtt_command_topic.equals(topic))
    // {

    //     if (memcmp(payload, BOILER_MQTT_PAYLOAD_ON, length) == 0)
    //     {
    //         boiler_on();
    //         client.publish(BOILER_MQTT_STATE_TOPIC, BOILER_MQTT_PAYLOAD_ON);
    //     }
    //     else
    //     {
    //         boiler_off();
    //         client.publish(BOILER_MQTT_STATE_TOPIC, BOILER_MQTT_PAYLOAD_OFF);
    //     }
    // }

}
