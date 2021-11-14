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
    analogWrite(power_pin, power);
}

void WaterPump::shut_off() {
    analogWrite(power_pin, LOW_POWER);    
}

void WaterPump::set_power(int power){
    if (power > HIGH_POWER){
        power = HIGH_POWER;
    }
    if (power < LOW_POWER){
        power = LOW_POWER;
    }
    this->power = power;
}

int WaterPump::get_power(){
    return power;
}