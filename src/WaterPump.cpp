#include "WaterPump.hpp"
#include "Arduino.h"


WaterPump::WaterPump(int power_pin, int direction_pin) {
    this->direction_pin = direction_pin;
    this->power_pin = power_pin;

    pinMode(direction_pin, OUTPUT);
    pinMode(power_pin, OUTPUT);
    digitalWrite(direction_pin, HIGH);
}

void WaterPump::turn_on() {
    analogWrite(power_pin, HIGH_POWER);
}

void WaterPump::shut_off() {
    analogWrite(power_pin, LOW_POWER);    
}