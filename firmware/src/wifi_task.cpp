#include "wifi_task.h"

WifiTask::WifiTask() {
#ifdef SECRETS_H
    ssid = WIFI_SSID;
    password = WIFI_PASSWORD;
#else
    ssid = nullptr;
    password = nullptr;
#endif
}

void WifiTask::initializeWifi() {
    WiFi.begin(this->ssid, this->password);
}

String WifiTask::getLocalIp() {
    if (WiFi.status() == WIFI_CONNECTED) {
        return WiFi.localIP().toString();
    } else {
        return WIFI_NOT_CONNECTED;
    }
}

bool WifiTask::isConnected() {
    return (WiFi.status() == WIFI_CONNECTED);
}

int WifiTask::getChannel() {
    if (WiFi.status() == WIFI_CONNECTED) {
        return WiFi.channel();
    } else {
        return -1; 
    }
}