#ifndef A2EEDDC9_441C_40E6_807C_55DEE2123DAB
#define A2EEDDC9_441C_40E6_807C_55DEE2123DAB

#define MAX_MOISTURE_IND 0
#define MIN_MOISTURE_IND 1

#include <Vector.h>
#include "WaterPump.hpp"
#include "LedMatrix.hpp"
#include "WaterHumiditySensor.hpp"
#include "ConfigView.hpp"
#include "AnalogButton.hpp"

typedef struct{
    ConfigView cv;
    int value;
} Constant;

/**
 * @brief Parent class all things concerning Plant does all the config and all the humidity checking
 * 
 */
class Plant{
    private:
        int min_moisture_pct;
        int max_moisture_pct;

        Constant constant[2]; //plant class has 2 constants that can be changed by the user

        WaterPump *wp;
        LedMatrix *lm;
        WaterHumiditySensor *wh;
        AnalogButton *ab;

        int max_config_screens = 2;
        ConfigView config_views[2];

        int config_numbers[2];
        int index_of_config_view = 0;

        int pct_validator(int pct);
        void set_index_of_config_view(button_val bv);
        void set_config_views();
        void config_views_show();

    public:
        /**
         * @brief Construct a new Plant object
         * 
         * @param min_moisture_pct 
         * @param max_moisture_pct 
         * @param wp - refrence to water pump object
         * @param lm - refrence to Led Matrix object
         * @param wh - refrence to Water Humidity Sensor
         * @param ab - refrence to AnalogButton
         */
        Plant(int min_moisture_pct, int max_moisture_pct, WaterPump *wp, LedMatrix *lm, WaterHumiditySensor *wh, AnalogButton *ab);
        
        /**
         * @brief does one step of the method
         *  checks the humidity and waters the plant if it below the min_moisture_pct
         * if select is pressed then the config screens come up on the LED Matrix
         * 
         */
        void step();

        /**
         * @brief initialized the plant
         * calibrated the water sensor and sets the brightness of the display 
         * 
         */
        void init();

        /**
         * @brief Sets the motor power
         * 
         * @param power 
         */
        void set_motor_power(int power);

        /**
         * @brief Set the display brithness
         * 
         * @param brightness 
         */
        void set_display_brightness(int brightness);

        /**
         * @brief Set the min moisture pct
         * 
         * @param min_moisture_pct 
         */
        void set_min_moisture_pct(int min_moisture_pct);

        /**
         * @brief Set the max moisture pct
         * 
         * @param max_moisture_pct 
         */
        void set_max_moisture_pct(int max_moisture_pct);
};

#endif /* A2EEDDC9_441C_40E6_807C_55DEE2123DAB */
