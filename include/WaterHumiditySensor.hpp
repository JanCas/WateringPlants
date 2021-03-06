#ifndef WATERHUMIDITYSENSOR_H_
#define WATERHUMIDITYSENSOR_H_
#include "LedMatrix.hpp"
#include "EEPROM_util.h"

/**
 * @brief 
 * The water sensor uses an inverse mapping for the humidity -> wet (low reading) - dry (high reading)
 */
class WaterHumiditySensor{
    public:
        WaterHumiditySensor(int pin_number);
        void calibrate(int low, int high);
        void calibrate();
        unsigned int read_current();
        float pct_between_bounds(int val);
        void init();
    private:
        int water_moisture;
        int air_moisture;
        int pin_number;
};

#endif