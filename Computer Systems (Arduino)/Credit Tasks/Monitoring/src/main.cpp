#include "DHT.h"
#include <Arduino.h>

int greenPin = 3;
int redPin = 4;
int tempPin = 2;
int soilPin = 0;
int DHTType = DHT22;
DHT dht(tempPin, DHTType);

void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);

  int sensorValue = analogRead(soilPin);
  int soilMoisture = map(sensorValue, 0, 1023, 0, 100);

  float temp = dht.readTemperature(false);
  float humidity = dht.readHumidity();

  digitalWrite(greenPin, HIGH);

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read!, trying again...");
    return;
  }

  if ((soilMoisture >= 10) && (temp >= 20) && (humidity >= 50)) {
    digitalWrite(redPin, HIGH);
  } else {
    digitalWrite(redPin, LOW);
  }

  Serial.println("Temperature: " + String(temp));
  Serial.println("Humidity: " + String(humidity));
  Serial.println("Soil Moisture: " + String(soilMoisture) + "%");
}