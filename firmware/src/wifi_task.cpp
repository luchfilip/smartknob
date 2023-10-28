#include "wifi_task.h"

WifiTask::WifiTask(const char *ssid, const char *password)
{
    this->ssid = ssid;
    this->password = password;
}

void WifiTask::initializeWifi()
{
    WiFi.begin(this->ssid, this->password);
    delay(10000);
}

String WifiTask::getLocalIp()
{
    if (WiFi.status() == WIFI_CONNECTED)
    {
        return WiFi.localIP().toString();
    }
    else
    {
        return "Not connected";
    }
}

bool WifiTask::getConnectionStatus()
{
    return (WiFi.status() == WIFI_CONNECTED);
}

int WifiTask::getChannel()
{
    if (WiFi.status() == WIFI_CONNECTED)
    {
        return WiFi.channel();
    }
    else
    {
        return -1;
    }
}
