#pragma once

#include <PubSubClient.h>

class MQTT
{
public:
    MQTT(String brokerIp, String brokerPass, uint16_t port=1883);

    void poll();

    static void mqtt_cb(char* topic, byte* payload, unsigned int length);

private:
    PubSubClient m_client;
};