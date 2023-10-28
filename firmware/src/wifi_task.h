#pragma once

#ifndef WIFI_TASK_H
#define WIFI_TASK_H

#include <Arduino.h>
#include <WiFi.h>
#include "secrets.h"

class WifiTask
{
public:
    WifiTask(const char *ssid, const char *password);
    void initializeWifi();
    String getLocalIp();
    bool getConnectionStatus();
    int getChannel();

private:
    const char *ssid;
    const char *password;
};

typedef enum
{
    WIFI_NO_SHIELD = WL_NO_SHIELD,
    WIFI_IDLE_STATUS = WL_IDLE_STATUS,
    WIFI_NO_SSID_AVAIL = WL_NO_SSID_AVAIL,
    WIFI_SCAN_COMPLETED = WL_SCAN_COMPLETED,
    WIFI_CONNECTED = WL_CONNECTED,
    WIFI_CONNECT_FAILED = WL_CONNECT_FAILED,
    WIFI_CONNECTION_LOST = WL_CONNECTION_LOST,
    WIFI_DISCONNECTED = WL_DISCONNECTED
} WIFI_CONFIG_STATUS;

#endif // WIFI_TASK_H
