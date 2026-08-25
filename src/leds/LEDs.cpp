#include <Arduino.h>
#include "leds/LEDs.h"

const int LED_RED = 21;
const int LED_YELLOW = 22;
const int LED_GREEN = 19;

void LEDs::begin() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    allof();
}

void LEDs::redOn() {
    digitalWrite(LED_RED, HIGH);
}
void LEDs::redOff() {
    digitalWrite(LED_RED, LOW);
}
void LEDs::yellowOn() {
    digitalWrite(LED_YELLOW, HIGH);
}
void LEDs::yellowOff() {
    digitalWrite(LED_YELLOW, LOW);
}
void LEDs::greenOn() {
    digitalWrite(LED_GREEN, HIGH);
}
void LEDs::greenOff() {
    digitalWrite(LED_GREEN, LOW);
}
void LEDs::allof() {
    redOff();
    yellowOff();
    greenOff();
}