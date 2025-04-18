#include <Arduino.h>
#include <Servo.h>

Servo motor;

int motorPin = 2;

void sweep();

void setup() { motor.attach(motorPin); }

void loop() {
  //     motor.write(90);
  //     delay(1000);
  //     motor.write(135);
  //     delay(1000);
  //     motor.write(180);
  //     delay(1000);
  //     motor.write(0);
  //     delay(1000);

  sweep();
}

void sweep() {
  int value = motor.read();

  while (value < 180) {
    value += 5;
    motor.write(value);
    delay(40);
  }

  while (value > 0) {
    value -= 5;
    motor.write(value);
    delay(40);
  }

  delay(1000);
}
