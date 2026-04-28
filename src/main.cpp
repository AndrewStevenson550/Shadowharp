#include <Arduino.h>
#include <HCSR04.h>

const int greenLed = 4;
const byte echoPin = 18;
const byte triggerPin = 5;
const int soundPin = 19;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
  Serial.begin(115200); // Start the communication at high speed
  pinMode(greenLed, OUTPUT);
  pinMode(soundPin, OUTPUT);
  digitalWrite(greenLed, HIGH);
  Serial.println("System Online...");
}

void loop() {
  // Get distance as a float for better precision
  float distance = distanceSensor.measureDistanceCm();

  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 200) {
    if (distance < 15) {
      // Danger level high: Constant Tone
      digitalWrite(soundPin, HIGH);
    } 
    else if (distance < 50) {
      // Danger level medium: Pulsing Tone
      digitalWrite(soundPin, HIGH);
      delay(100);
      digitalWrite(soundPin, LOW);
      delay(100);
    } 
    else {
      // Safe distance: Turn off buzzer
      digitalWrite(soundPin, LOW);
    }
  } 
  else {
    // Out of range or error: Turn off buzzer
    digitalWrite(soundPin, LOW);
  }

  delay(50); // Small delay to keep the simulation smooth
}
