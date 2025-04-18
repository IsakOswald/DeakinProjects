#include <Arduino.h>

const int buttonRED = 2;
const int ledRED = 3;
const int buttonBLUE = 4;
const int ledBLUE = 5;

void setup()
{
  pinMode(buttonRED, INPUT);
  pinMode(ledRED, OUTPUT);
  pinMode(buttonBLUE, INPUT);
  pinMode(ledBLUE, OUTPUT);
}

void loop()
{
  if (digitalRead(buttonRED) == HIGH)
    digitalWrite(ledRED, HIGH);
  else
  {
    digitalWrite(ledRED, LOW);
  }

  if (digitalRead(buttonBLUE) == HIGH)
    digitalWrite(ledBLUE, HIGH);
  else
  {
    digitalWrite(ledBLUE, LOW);
  }
}
