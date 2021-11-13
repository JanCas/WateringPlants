#include <Arduino.h>
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"
#include "AnalogButton.hpp"
#include "WaterPump.hpp"


const uint8_t DATA_IN_PIN = 12;
const uint8_t CLK_PIN = 11;
const uint8_t CS_PIN = 10;

const uint8_t WATER_SENSOR_PIN = A0;

const uint8_t MOTOR_DIRECTION_PIN = 4;
const uint8_t MOTOR_SPEED_PIN = 5;

LedMatrix lm = LedMatrix(DATA_IN_PIN, CLK_PIN, CS_PIN);
WaterHumiditySensor wh = WaterHumiditySensor(WATER_SENSOR_PIN);
WaterPump wp = WaterPump(MOTOR_SPEED_PIN, MOTOR_DIRECTION_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Calibrating the sensor");
  delay(5000);
  wh.calibrate();
  wp.set_power(25);
  Serial.println("Inser the sensor into the plant one minute before readings and watering begins");
  lm.set_brightness(15);
  delay(30000);
  Serial.println("Wait over");
}


void loop() {
  // put your main code here, to run repeatedly:
  int water_moisture_pct = wh.pct_between_bounds(wh.read_current());
  lm.clear();
  lm.display_integer(water_moisture_pct);

  if (water_moisture_pct < 20){
    wp.turn_on();
    while (wh.pct_between_bounds(wh.read_current()) < 50){
      delay(500);
    }
    wp.shut_off();
  }
  delay(5000);
}