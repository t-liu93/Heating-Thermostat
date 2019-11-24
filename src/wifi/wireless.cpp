#include "wireless.h"

#define WIFI_SSID "Home"
#define WIFI_PASSWORD "ireallydontknow"

static_assert(WIFI_SSID, "Set WIFI defines for compiling");

void wifi_initialization()
{
    Serial.begin(115200);
    Serial.println();

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}