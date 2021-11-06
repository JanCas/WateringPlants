#include <Arduino.h>
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"

const uint8_t DATA_IN_PIN = 12;
const uint8_t CLK_PIN = 10;
const uint8_t CLS_PIN = 11;

const uint8_t WATER_SENSOR_PIN = A0;

//LedMatrix lm = LedMatrix(DATA_IN_PIN, CLK_PIN, CLS_PIN);
WaterHumiditySensor wh = WaterHumiditySensor(WATER_SENSOR_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  lm.clear();
//  lm.wake_up();
//  lm.set_brightness(10);
  //Serial.println("got here");
  //lm.display_integer(100);
}

void loop() {
  // put your main code here, to run repeatedly:
/*
  lm.clear();
  
  lm.display_integer(n);
  Serial.println(n);

  delay(1000);
*/

  int sensor_reading = wh.read_current();
  Serial.println(sensor_reading);

  delay(1000);  
}