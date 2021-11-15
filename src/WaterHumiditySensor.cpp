#include "WaterHumiditySensor.hpp"
#include "Arduino.h"

WaterHumiditySensor::WaterHumiditySensor(int pin_number){
    this->pin_number = pin_number;
    pinMode(pin_number, INPUT);
}

void WaterHumiditySensor::calibrate(int water_moisture, int air_moisture) {
    this->water_moisture = water_moisture;
    this->air_moisture = air_moisture;
}


void WaterHumiditySensor::calibrate() {
    unsigned int water_moisture = __INT_MAX__;
    unsigned int air_moisture = 0;

    // Serial.println("Leave the sensor in the air will be taking reading for the next 20 seconds");


    // take 20 readings 1 second apart to find the humidity of the surrounding air
    for (int i = 0; i < 20; i++)
    {
        int currentReading = read_current();
        if (currentReading > air_moisture){
            air_moisture = currentReading;
        }
        delay(1000);
    }

    // // Serial.println("Please insert the Sensor into water");
    // Serial.println("30 seonds until the next reading begins");
    delay(30000);

    // take 20 readings 1 second apart to find the humidity of water
    // Serial.println("reading from water");
    for (int i = 0; i < 20; i++)
    {
        int currentReading = read_current();
        if (currentReading < water_moisture){
            water_moisture = currentReading;
        }
        delay(1000);
    }

    // calibrate the sensor
    calibrate(water_moisture, air_moisture);

    // Serial.print("Calibration done values are -> Air Moisture: ");
    // Serial.print(this->air_moisture);
    // Serial.print(" - Water Moisture: ");
    // Serial.println(this->water_moisture);
}

float WaterHumiditySensor::pct_between_bounds(int val){
    float low_bound_f = (float) air_moisture;
    float high_bound_f = (float) water_moisture;
    float val_f = (float) val;

    return ((val_f - low_bound_f) * 100) / (high_bound_f - low_bound_f);
}

unsigned int WaterHumiditySensor::read_current(){
    return analogRead(pin_number);
}