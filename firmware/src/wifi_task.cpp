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

bool WifiTask::getStatus()
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

String WifiTask::getFrequency()
{
    if (WiFi.status() == WIFI_CONNECTED)
    {
        return (WiFi.channel() <= 14) ? "2.4GHz" : "5GHz";
    }
    else
    {
        return "Not connected";
    }
}
