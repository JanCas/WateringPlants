#include <Arduino.h>
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"
#include "AnalogButton.hpp"
#include "WaterPump.hpp"
#include "Plant.hpp"
#include "ConfigView.hpp"



const uint8_t DATA_IN_PIN = 12;
const uint8_t CLK_PIN = 11;
const uint8_t CS_PIN = 10;

const uint8_t WATER_SENSOR_PIN = A0;
const uint8_t ANALOG_BUTTON_PIN = A7;

const uint8_t MOTOR_DIRECTION_PIN = 4;
const uint8_t MOTOR_SPEED_PIN = 5;

LedMatrix lm(DATA_IN_PIN, CLK_PIN, CS_PIN);
WaterHumiditySensor wh(WATER_SENSOR_PIN);
WaterPump wp(MOTOR_SPEED_PIN, MOTOR_DIRECTION_PIN);

AnalogButton ab(ANALOG_BUTTON_PIN);
int num = 55;
ConfigView cv("H PC", &lm);

Plant plant(50, 70, &wp, &lm, &wh, &ab);
int i = 0;

void func(int &j){
  j++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
/*
  plant.init();
  Serial.println("Insert the Sensor into the Plant -> starting readings and water in one minure");
  delay(60000);
  plant.set_display_brightness(15);
  Serial.println("Wait over");
  */
  button_val bv = cv.view_function(&ab, num);
  Serial.println(ab.to_string(bv));
  Serial.println(num);
}


void loop() {
  // put your main code here, to run repeatedly:
  //plant.step();
  //Serial.println(ab.to_string(ab.read_button()));
  delay(100);
}
