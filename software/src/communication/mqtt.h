#pragma once

#include <PubSubClient.h>

class MQTT
{
public:
    static void connect(String brokerIp="10.238.75.62", uint16_t brokerPort=1883, String brokerUserName="mqtt", String brokerPass="mqtt");
    static void poll();
    static void checkConnection();

    static void mqtt_cb(char* topic, byte* payload, unsigned int length);

    static PubSubClient client;
    static WiFiClient wifiClient;

    static String ip;
    static uint16_t port;
    static String uName;
    static String pass;

private:
    MQTT() {}
};