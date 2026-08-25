#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

class WiFiManager {
public:
    void begin();
    bool isConnected();
    void printStatus();

};

#endif // WIFI_MANAGER_H