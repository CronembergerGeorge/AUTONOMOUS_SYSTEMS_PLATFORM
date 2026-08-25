#include "DHTSensor.h"
#include <DHT.h>

#define DHT_PIN 19
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

float temperature = 0.0;
float humidity = 0.0;
bool errorFlag = false;

void DHTSensor::begin() {
    // Inicialização do sensor DHT
    dht.begin();
}
void DHTSensor::update() {
    // Atualização dos valores do sensor DHT
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    errorFlag = isnan(temperature) || isnan(humidity); // Verifica se houve erro na leitura
}
float DHTSensor::getTemperature() {
    // Retorna a temperatura medida pelo sensor DHT
    return temperature;
}
float DHTSensor::getHumidity() {
    // Retorna a umidade medida pelo sensor DHT
    return humidity;
}
bool DHTSensor::hasError() {
    // Retorna true se houver algum erro na leitura do sensor DHT
    return errorFlag;
}
