#ifndef A2EEDDC9_441C_40E6_807C_55DEE2123DAB
#define A2EEDDC9_441C_40E6_807C_55DEE2123DAB

#include <Vector.h>
#include "WaterPump.hpp"
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"
#include "ConfigView.hpp"
#include "AnalogButton.hpp"


class Plant{
    private:
        int min_moisture_pct;
        int max_moisture_pct;
        WaterPump *wp;
        LedMatrix *lm;
        WaterHumiditySensor *wh;
        int pct_validator(int pct);
        Vector<ConfigView> config_views;
        int config_numbers[2];
        AnalogButton *ab;
        int index_of_config_view = 0;
        void set_index_of_config_view(button_val bv);
        void set_config_views();

    public:
        Plant(int min_moisture_pct, int max_moisture_pct, WaterPump *wp, LedMatrix *lm, WaterHumiditySensor *wh, AnalogButton *ab);
        void step();
        void init();
        void set_motor_power(int power);
        void set_display_brightness(int brightness);
        void set_min_moisture_pct(int min_moisture_pct);
        void set_max_moisture_pct(int max_moisture_pct);
        void config_views_show();
};

#endif /* A2EEDDC9_441C_40E6_807C_55DEE2123DAB */
