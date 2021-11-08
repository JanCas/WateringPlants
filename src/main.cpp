#include <Arduino.h>
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"

const uint8_t DATA_IN_PIN = 12;
const uint8_t CLK_PIN = 10;
const uint8_t CLS_PIN = 11;

const uint8_t WATER_SENSOR_PIN = A0;

LedMatrix lm = LedMatrix(DATA_IN_PIN, CLK_PIN, CLS_PIN);
WaterHumiditySensor wh = WaterHumiditySensor(WATER_SENSOR_PIN);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lm.clear();
  lm.wake_up();
  lm.set_brightness(10);

  Serial.println("Calibrating the sensor");

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(1000);
  lm.clear();
  int sensor_reading = wh.read_current();
  Serial.println(sensor_reading);
  int pct_between = (int) wh.pct_between_bounds(sensor_reading);
  Serial.println(pct_between);
  Serial.println();

  lm.display_integer(pct_between);

}