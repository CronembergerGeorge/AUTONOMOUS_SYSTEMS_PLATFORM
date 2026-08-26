#include <Arduino.h>

#include "sensors/DHTSensor.h"
#include "leds/LEDs.h"
#include "wifi/WiFiManager.h"
#include "sensors/UltrasonicSensor.h"
#include "system/SensorData.h"
#include "system/Diagnostic.h"

//System
SensorData sensorData;
//LEDs
LEDs leds;
//Sensores
DHTSensor dhtSensor;
UltrasonicSensor ultrasonicSensor;
//Wifi
WiFiManager wifiManager;

unsigned long lastSensorReadTime = 0;
const unsigned long SENSOR_INTERVAL = 2000;

void setup() {

  Serial.begin(115200);
  dhtSensor.begin();
  leds.begin();
  wifiManager.begin();
  ultrasonicSensor.begin();

  Serial.println();
  Serial.println("=== Modular Autonomous System ===");
  wifiManager.printStatus();
}


void loop() {

  unsigned long currentTime = millis();
  if (currentTime - lastSensorReadTime >= SENSOR_INTERVAL) {
    lastSensorReadTime = currentTime;
    dhtSensor.update();
    ultrasonicSensor.update();

    sensorData.temperature = dhtSensor.getTemperature();
    sensorData.humidity = dhtSensor.getHumidity();
    sensorData.distance = ultrasonicSensor.getDistance();

    sensorData.dhtError = dhtSensor.hasError();
    sensorData.ultrasonicError = ultrasonicSensor.hasError();

    if(sensorData.dhtError){
      leds.redOn();
      leds.greenOff();
    } else {
      leds.redOff();
      leds.greenOn();
    }
    if(sensorData.ultrasonicError){
      leds.yellowOff();
    } else {
      leds.yellowOn();
    }
    
    printSensorData(sensorData);
    Serial.print("WiFi Status: ");
    wifiManager.printStatus();
    
    Serial.println("-----------------------");
  }
}