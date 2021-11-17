#include <Arduino.h>
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"
#include "AnalogButton.hpp"
#include "WaterPump.hpp"
#include "Plant.hpp"
#include "ConfigView.hpp"
#include "avr8-stub.h"



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



// ConfigView cv("H PC", &lm);

Plant plant(50, 70, &wp, &lm, &wh, &ab);

int num = 55;
int num2 = 100;

int num_arr[] = {num, num2};

void f(int &i, int &j){
  i++;
  j++;
}

void setup() {
  // put your setup code here, to run once:
 debug_init();
  // Serial.begin(9600);
  // plant.init();
/*
  f(num_arr[0], num_arr[1]);

  Serial.println(num_arr[0]);
  Serial.println(num_arr[1]);

  Serial.println(num);
  Serial.print(num2);
*/
  plant.init();
  /*
  Serial.println("Insert the Sensor into the Plant -> starting readings and water in one minure");
  delay(60000);
  plant.set_display_brightness(15);
  Serial.println("Wait over");
*/
}


void loop() {
  // put your main code here, to run repeatedly:
  plant.step();
  //Serial.println(ab.to_string(ab.read_button()));
  // plant.step();
  //delay(500);
}
