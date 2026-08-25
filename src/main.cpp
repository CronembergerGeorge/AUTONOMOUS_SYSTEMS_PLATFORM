#include <Arduino.h>

#include "sensors/DHTSensor.h"
#include "leds/LEDs.h"
#include "wifi/WiFiManager.h"
#include "sensors/UltrasonicSensor.h"

DHTSensor dhtSensor;
LEDs leds;
WiFiManager wifiManager;
UltrasonicSensor ultrasonicSensor;

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
  dhtSensor.update();
  ultrasonicSensor.update();

  if(dhtSensor.hasError()){
    Serial.println("Error reading DHT sensor.");
    leds.redOn();
    leds.greenOff();
  } else {
    leds.redOff();
    leds.greenOn();
  }
  if(ultrasonicSensor.hasError()){
    Serial.println("Error reading Ultrasonic sensor.");
    leds.yellowOn();
  } else {
    leds.yellowOff();
    Serial.print("Distance: ");
    Serial.print(ultrasonicSensor.getDistance());
    Serial.println(" cm");
  }
  Serial.print("Temperature: ");
  Serial.print(dhtSensor.getTemperature());
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(dhtSensor.getHumidity());
  Serial.println(" %");
  
  Serial.println("-----------------------");
  delay(2000); // Aguarda 2 segundos antes da próxima leitura
}