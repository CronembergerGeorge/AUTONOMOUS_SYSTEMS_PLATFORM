#include "sensors/UltrasonicSensor.h"
#include <Arduino.h>

#define TRIGGER_PIN 4
#define ECHO_PIN 2

float distance = 0.0;
bool error = false;

void UltrasonicSensor::begin() {

    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIGGER_PIN, LOW);

    // Inicialização do sensor ultrassônico
}
void UltrasonicSensor::update() {

    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000); // Timeout de 30ms

    if (duration == 0) {
        error = true; // Erro na leitura do sensor
        return;
    }

    distance = (duration * 0.0343) / 2; // Calcula a distância em centímetros
    error = false;
    
    // Atualização da leitura do sensor ultrassônico
}
float UltrasonicSensor::getDistance() {
    // Retorna a distância medida pelo sensor ultrassônico
    return distance;
}
bool UltrasonicSensor::hasError() {
    // Retorna true se houver algum erro na leitura do sensor ultrassônico
    return error;
}