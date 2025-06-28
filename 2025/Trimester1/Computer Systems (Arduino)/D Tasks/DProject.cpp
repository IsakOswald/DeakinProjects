
#include <Servo.h>

// Our Pins
constexpr int trigPin = 7;
constexpr int echoPin = 8;
constexpr int ledRed = 2;
constexpr int buzzerPin = 13;
constexpr int motorPin = 9;
constexpr int tiltPin = 3;
constexpr int ledOrange = 4;
// Functions
void foodLow(long dist);
void fallenBowl();

// Motor object
Servo motor;

// Setup & Inits
void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledRed, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    motor.attach(motorPin);
    pinMode(tiltPin, INPUT_PULLUP);
    pinMode(ledOrange, OUTPUT);
}

void loop()
{
    // Send a pulse to the trig pin to start the measurement
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters
    long distance = duration * 0.0344 / 2;  // Speed of sound is 0.0344 cm/us, divided by 2 for round trip

    // Serial.print("Distance: ");
    // Serial.print(distance);
    // Serial.println(" cm");

    // Call the functions
    foodLow(distance);
    fallenBowl();

    delay(500);
}

// Chrck if thr food is low
void foodLow(long dist)
{
    // If the food is low...
    if (dist > 240)
    {
        digitalWrite(ledRed, HIGH);
        digitalWrite(buzzerPin, HIGH);
        motor.write(180);
    }

    // Otherwise it is not low..
    else
    {
        digitalWrite(ledRed, LOW);
        digitalWrite(buzzerPin, LOW);
        motor.write(0);
    }
}

// If the bowl has fallen...
void fallenBowl()
{
    // Save the sensor state.
    int sensorState = digitalRead(tiltPin);

    // Check if fallen..
    if (sensorState == LOW)
    {
        digitalWrite(ledOrange, HIGH);
    }
    // Otherwise not fallen.
    else
    {
        digitalWrite(ledOrange, LOW);
    }
}
