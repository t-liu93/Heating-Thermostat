#ifndef __SRC_COMMUNICATION_H
#define __SRC_COMMUNICATION_H

/**
 * WIFI control
 */
void wifi_initialization();

bool wifi_is_connected();

void mqtt_initialization();

void mqtt_poll();

#endif