// wifi_task.h
#ifndef WIFI_TASK_H
#define WIFI_TASK_H

#include <Arduino.h>
#include <WiFi.h>

#define WifiSSID "Haseeb"
#define WifiPassword  "hasifast2023"


class WifiTask
{
public:
    WifiTask(const char *ssid, const char *password);
    void begin();     // Initialize WiFi
    String localIP(); // Retrieve the local IP address
    bool status();    // Check if WiFi is connected
    int channel();    // Get the current WiFi channel
    String freq();    // Determine the frequency band

private:
    const char *ssid;
    const char *password;
};

#endif // WIFI_TASK_H
