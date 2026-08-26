#include "Diagnostic.h"
#include <Arduino.h>

void printSensorData(const SensorData& data){

    Serial.println("=== Sensor Data ===");

    if(data.dhtError){
        Serial.println("DHT Sensor Error.");
    } else {
        Serial.print("Temperature: ");
        Serial.print(data.temperature);
        Serial.println(" *C");
        Serial.print("Humidity: ");
        Serial.print(data.humidity);
        Serial.println(" %");
    }
    if(data.ultrasonicError){
        Serial.println("Ultrasonic Sensor Error.");
    } else {
        Serial.print("Distance: ");
        Serial.print(data.distance);
        Serial.println(" cm");
    }
    Serial.println("-----------------------");
}