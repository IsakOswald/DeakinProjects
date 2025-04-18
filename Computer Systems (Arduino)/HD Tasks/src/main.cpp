#include "classes.hpp"
#include "consts.hpp"
#include "includes.hpp"
#include "menu_template.hpp"
#include "utils.hpp"

unsigned long lastSensorCheck = 0;
const unsigned long sensorInterval = 2000; 

Commands commands;
Servo servo;
DHT dht(dht_pin, dht_type);

void run_main_menu(int input);

void setup()
{
    pinMode(led_yellow, OUTPUT);
    pinMode(led_red, OUTPUT);
    pinMode(led_green, OUTPUT);
    servo.attach(servo_pin);
    dht.begin();

    Serial.begin(9600);

    servo.write(0);

    commands.ledOn(led_green);
}

void loop()
{
    commands.monitorSound();
    commands.monitorTilt();
    // 1. Check sensors every 2 seconds
    unsigned long currentMillis = millis();
    if (currentMillis - lastSensorCheck >= sensorInterval)
    {
        lastSensorCheck = currentMillis;

        commands.monitorTemp(); 
        commands.monitorHum();   
    }

    if (Serial.available() > 0)
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (isInteger(input))
        {
            main_menu();
            commands.usr_command = input.toInt();
            Serial.println(commands.usr_command);

            run_main_menu(commands.usr_command);
        }

        else
        {
            Serial.println("Incorrect input.");
        }
    }
}

void run_main_menu(int input)
{
    switch (input)
    {
        case 1:
            commands.ledOn(led_yellow);
            Serial.println("LED was switched On!");
            Serial.println("0 Errors.");
            break;
        case 2:
            commands.ledOff(led_yellow);
            Serial.println("LED was switched On!");
            Serial.println("0 Errors.");
            break;
        case 3:
            Serial.println("LED is blinking!");
            commands.ledBlink(led_yellow, 15);
            Serial.println("0 Errors.");
            break;
        case 4:
            commands.lockDoor(led_red);
            Serial.println("Door successfully locked and lock LED was switched to on!");
            Serial.println("0 Errors.");
            break;
        case 5:
            commands.unlockDoor(led_red);
            Serial.println("Door successfully unlocked and lock LED was switched to off!");
            Serial.println("0 Errors.");
            break;
        case 6:
            commands.readTemperature();
            delay(500);
            commands.readTemperature();
            delay(500);
            commands.readTemperature();
            delay(500);

            break;
        case 7:
            commands.readHumidity();
            delay(500);
            commands.readHumidity();
            delay(500);
            commands.readHumidity();
            delay(500);
            break;
        case 8:
            commands.readSoundLevel();
            delay(500);
            commands.readSoundLevel();
            delay(500);
            commands.readSoundLevel();
            delay(500);
            break;
        case 9:
            commands.readTilt();
            delay(500);
            commands.readTilt();
            delay(500);
            commands.readTilt();
            delay(500);
            break;
        case 99:
            Serial.println("System is deactivated! Restart/re-connect to resume!");
            commands.ledOff(led_green);
            while (true)
            {
            }
            break;
        case 0:
            break;
        default:
            Serial.println("Invalid selection!");
            break;
    }
}
