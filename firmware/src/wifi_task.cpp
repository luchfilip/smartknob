// wifi_task.cpp
#include "wifi_task.h"

WifiTask::WifiTask(const char *ssid, const char *password)
{
    this->ssid = ssid;
    this->password = password;
}

void WifiTask::begin()
{
    // Initialize the serial communication if it's not initialized elsewhere
    WiFi.begin(this->ssid, this->password);
    delay(10000);
}

String WifiTask::localIP()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        return WiFi.localIP().toString();
    }
    else
    {
        return "Not connected";
    }
}

bool WifiTask::status()
{
    return (WiFi.status() == WL_CONNECTED);
}

int WifiTask::channel()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        return WiFi.channel();
    }
    else
    {
        return -1; // Return -1 or any other indicator of "no channel"
    }
}

String WifiTask::freq()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        // ESP32 is typically 2.4GHz only, but you're preparing for future possibilities
        return (WiFi.channel() <= 14) ? "2.4GHz" : "5GHz";
    }
    else
    {
        return "Not connected";
    }
}
