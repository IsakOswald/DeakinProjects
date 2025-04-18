#include "consts.hpp"
#include "includes.hpp"

extern Servo servo;
extern DHT dht;

void Commands::ledOff(int pin) { digitalWrite(pin, LOW); }

void Commands::ledOn(int pin) { digitalWrite(pin, HIGH); }

void Commands::ledBlink(int pin, int blinks)
{
    for (int i = 0; i < blinks; i++)
    {
        digitalWrite(pin, HIGH);
        delay(100);
        digitalWrite(pin, LOW);
        delay(100);
    }
}

void Commands::lockDoor(int led)
{
    servo.write(90);
    delay(500);
    ledOn(led);
}

void Commands::unlockDoor(int led)
{
    servo.write(0);
    delay(500);
    ledOff(led);
}

void Commands::activateAlarm(int iters)
{
    Serial.println("SECURITY RISK DETECTED!!!");

    lockDoor(led_red);

    for (int i = 0; i < iters; i++)
    {
        ledBlink(led_green, 5);
        ledBlink(led_red, 5);
        ledBlink(led_yellow, 5);
        delay(20);
    }

    delay(500);

    ledOn(led_green);
    ledOn(led_red);
}


void Commands::monitorHum()
{
    float humidity = dht.readHumidity();

    if (isnan(humidity))
    {
        return; 
    }


    if (humidity < 30 || humidity > 60)
    {
        clear_terminal();
        Serial.println("HUMIDITY ISSUE:" + String(humidity));
        activateAlarm(1);
    }
}


void Commands::monitorTemp()
{
    float temp = dht.readTemperature();

    if (isnan(temp))
    {
        return;  
    }

  
    if (temp < 15 || temp > 30)
    {
        clear_terminal();
        Serial.println("TEMP ISSUE:" + String(temp));
        activateAlarm(1);
    }
}

void Commands::readHumidity() const
{
    float humidity = dht.readHumidity();
    if (isnan(humidity))
    {
        Serial.println("Failed to read humidity.");
        return;
    }
    Serial.println("Humidity: " + String(humidity) + "%");
}

void Commands::readTilt() const
{
    int tiltState = digitalRead(tilt_pin);

    if (tiltState == LOW)
    {
        Serial.println("No tampering detected!");
    }
    else
    {
        Serial.println("Tampering Detected!");
    }
}

void Commands::monitorTilt()
{
    int currentTiltState = digitalRead(tilt_pin);


    if (lastTiltState == HIGH && currentTiltState == LOW)
    {
        clear_terminal();
        Serial.println("TILT DETECTED!");
        activateAlarm(1);
    }


    lastTiltState = currentTiltState;
}

void Commands::readTemperature() const
{
    float temp = dht.readTemperature();
    if (isnan(temp))
    {
        Serial.println("Failed to read temperature.");
        return;
    }
    Serial.println("Temperature: " + String(temp) + "°C");
}

void Commands::monitorSound()
{
    int soundLevel = analogRead(sound_pin); 

    
    if (soundLevel > 200)
    {
        clear_terminal();
        Serial.println("LOUD SOUND DETECTED: " + String(soundLevel));
        activateAlarm(1);
    }
}

void Commands::readSoundLevel() const
{
    int soundLevel = analogRead(sound_pin); 

    Serial.println("Sound Level: " + String(soundLevel));
}

Commands::Commands() : usr_command(0) {}