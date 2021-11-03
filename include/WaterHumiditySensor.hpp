#include "Sensor.hpp"

class WaterHumiditySensor: public Sensor{
    public:
        WaterHumiditySensor(int pinNumber);
        void calibrate(int low, int high);
        void calibrate();
        int read_current();
        float pct_between_bounds(int val);
    private:
        int low_bound;
        int high_bound;
};