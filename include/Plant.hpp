#ifndef A2EEDDC9_441C_40E6_807C_55DEE2123DAB
#define A2EEDDC9_441C_40E6_807C_55DEE2123DAB

#include "WaterPump.hpp"
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"

class Plant{
    private:
        int min_moisture_pct;
        int max_moisture_pct;
        WaterPump *wp;
        LedMatrix *lm;
        WaterHumiditySensor *wh;
        int pct_validator(int pct);

    public:
        Plant(int min_moisture_pct, int max_moisture_pct, WaterPump *wp, LedMatrix *lm, WaterHumiditySensor *wh);
        void step();
        void init();
        void set_motor_power(int power);
        void set_display_brightness(int brightness);
        void set_min_moisture_pct(int min_moisture_pct);
        void set_max_moisture_pct(int max_moisture_pct);
};

#endif /* A2EEDDC9_441C_40E6_807C_55DEE2123DAB */
