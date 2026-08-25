#include <Arduino.h>
#include "wifi/WiFiManager.h"
#include <WiFi.h>

const char* ssid = "Q1_24";
const char* password = "4a215c454e";

void WiFiManager::begin() {
    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi");

    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected.");

}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void WiFiManager::printStatus(){

    if(isConnected()){
        Serial.println("WiFi: ONLINE");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }else{
        Serial.println("WiFi: OFFLINE");
    }
}
