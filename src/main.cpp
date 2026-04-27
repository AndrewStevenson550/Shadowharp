#include <Arduino.h>

// Most ESP32 boards have an internal LED on Pin 2
const int redLed = 2;
const int greenLed = 4;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(greenLed, HIGH);
}

void loop() {
  digitalWrite(redLed, HIGH);
  
  delay(500);
  
  digitalWrite(redLed, LOW);
  
  delay(500);
}
