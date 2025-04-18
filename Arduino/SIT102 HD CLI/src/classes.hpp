#pragma once
#include "includes.hpp"

class Commands
{
   public:
    int usr_command;
    mutable int lastTiltState = HIGH;

    Commands();

    void ledOn(int pin);
    void ledOff(int pin);
    void ledBlink(int pin, int blinks);
    void lockDoor(int led);
    void unlockDoor(int led);
    void monitorTemp();
    void activateAlarm(int iters);
    void monitorHum();
    void readTemperature() const;
    void readHumidity() const;
    void monitorSound();
    void readSoundLevel() const;
    void readTilt() const;
    void monitorTilt();
};