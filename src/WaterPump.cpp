#include "WaterPump.hpp"
#include "Arduino.h"


WaterPump::WaterPump(int power_pin, int direction_pin) {
    this->direction_pin = direction_pin;
    this->power_pin = power_pin;
    pinMode(direction_pin, OUTPUT);
}

void WaterPump::turn_on() {
    
}

void WaterPump::shut_off() {
    
}
