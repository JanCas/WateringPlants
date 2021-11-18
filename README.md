# Moisture Based Automatic Plant Watering with Arduino UNO

This is a moisture controlled watering system. It reads the current moisture of the plant and then checks it against a *minimum moisture value*. If the current moisture is less then the *minumum moisture value* then it start watering until the moisture in the pot is at the *max moisture value*

The current defualt are:
- *min moisture value* : 50%
- *max moisture value* : 70%

These can be changed in the config screens

## MARTERIALS

The materials that were used in this project are as follows:
- DFRobots Romeo (runs on arduino uno platform) [Romeo V1.3](https://www.dfrobot.com/product-656.html)
- MAX 7219 LED 7segment display [Amazon](https://www.amazon.com/gp/product/B086GKV958/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)
- Gikfun DC 2.5V-6V Micro Submersible Mini Water Pump [Amazon](https://www.amazon.com/gp/product/B0957BS936/ref=ppx_yo_dt_b_asin_title_o07_s00?ie=UTF8&psc=1)
- Songhe Capacitive Soil Moisture Sensor [Amazon](https://www.amazon.com/gp/product/B07SYBSHGX/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

## SETUP

The code was compiled and uploaded using the [Platform IO IDE](https://platformio.org/platformio-ide)

### Pin Configuration

- LED Display
  - VCC -> 5V
  - GND -> GND
  - DIN -> 12
  - CS -> 10
  - CLK -> 11
- Water Humidity Sensor
  - VCC -> 3.3V
  - GND -> GND
  - AIN -> A0 (analog input)
- Water Pump
  - Direction pin -> 4
  - Speed pin -> 5

The Romeo board has a built in motor shield connected to pins 4&5. The red wire from the pump should go into the positive side of the output (designated by a small + on the side) and the black wire on the right side.

### Running the first time

1. when the code has been uploaded to the Romeo it is going to start a calibration process. The serial monitor will guide you through this process.
    1. It will take readings from the water humidity sensor in the air
    2. It will take readings from the water humidity sensor in water
2. Once that calibration is done it will give you one minute to insert the sensor into the plant pot
3. It will then display the current moisture % of the soil where 0% is air and 100% is water
4. To enter the Config Screens click the *select* button on the board

## Config Screens

There are currently 2 config screens implemented:
1. The config screen to change the *max moisture value*:
  - This Config Screen has the following text: **H Pc  70**
  - use the TOP and BOTTOM buttons on the board to increment/decrement the value
  - the value is bound by *min moisture value* < *max moisture value* <= 100
2. The config screen to change the *min moisture value*
  - This Config Screen has the following text: **L Pc  50**
  - use the TOP and BOTTOM buttons on the board to increment/decrement the value
  - the value is bound by 0 <= *min moisture value* < *max moisture value*

To cycle between the 2 screens press the LEFT or RIGHT button. To exit the config screen just press the SELECT button 
