#ifndef WATERHUMIDITYSENSOR_H_
#define WATERHUMIDITYSENSOR_H_
#include "LedMatrix.hpp"


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
    private:
        int water_moisture;
        int air_moisture;
        int pin_number;
};

#endif