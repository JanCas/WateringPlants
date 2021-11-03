#include "WaterHumiditySensor.hpp"
#include "Arduino.h"

WaterHumiditySensor::WaterHumiditySensor(int pinNumber) :Sensor(pinNumber){
    pinMode(pinNumber, INPUT);
}

void WaterHumiditySensor::calibrate(int low, int high) {
    this->low_bound = low;
    this->high_bound = high;
}


void WaterHumiditySensor::calibrate() {
    unsigned int min = __INT_MAX__;
    unsigned int max = 0;

    // take 20 readings .1 seconds apart to find the humidity of the surrounding air
    for (int i = 0; i < 20; i++)
    {
        int currentReading = read_current();
        if (currentReading < min){
            min = currentReading;
        }
        delay(100);
    }

    Serial.print("Please insert the Sensor into water \n");
    Serial.print("30 seonds until the next reading begins");
    delay(30000);

    // take 20 readings .1 seconds apart to find the humidity of water
    for (int i = 0; i < 20; i++)
    {
        int currentReading = read_current();
        if (currentReading > max){
            max = currentReading;
        }
        delay(100);
    }

    // calibrate the sensor
    calibrate(min, max);
}

float WaterHumiditySensor::pct_between_bounds(int val){
    float low_bound_f = (float) low_bound;
    float high_bound_f = (float) high_bound;
    float val_f = (float) val;

    return ((val_f - low_bound_f) * 100) / (high_bound_f - low_bound_f);
}

void WaterHumiditySensor::calibrate(int low, int high){
    low_bound = low;
    high_bound = high;

    Serial.println("LOW: " + low_bound + " HIGH: " + high_bound);
}

int WaterHumiditySensor::read_current(){
    return analogRead(pinNumber);
}