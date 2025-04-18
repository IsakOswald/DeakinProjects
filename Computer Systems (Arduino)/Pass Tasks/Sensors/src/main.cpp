#include <Arduino.h>
int sensorPin = 0;
int ledRED = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledRED, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int moistureLevel = map(sensorValue, 0, 1023, 0, 100);

  Serial.println("Moisture level: " + String(moistureLevel) + "%");
  if (moistureLevel >= 15) {
    digitalWrite(ledRED, HIGH);
  }

  else {
    digitalWrite(ledRED, LOW);
  }

  delay(2000);
}
