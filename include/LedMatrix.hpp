
#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

#include "LedControl.h"

/**
 * @brief 
 * class for controlling a MAX7219 driver LED Matrix display
 */
class LedMatrix{
    public:
        /**
         * @brief Construct a new Led Matrix object
         * alls the pins are digital pins
         * 
         * also initializes the board using the init method
         * 
         * @param data_in_pin 
         * @param clk_pin 
         * @param load_pin (called CS pin on the display)
         */
        LedMatrix(int data_in_pin, int clk_pin, int load_pin);

        /**
         * @brief displays an integer on the display.
         * 
         * @param number 
         */
        void display_integer(int number);

        /**
         * @brief shuts down the display
         */
        void shutdown();

        /**
         * @brief wake's up the display
         */
        void wake_up();

        /**
         * @brief Sets the brightness of the display
         * 
         * @param intensity (0-15)
         */
        void set_brightness(int intensity);

        /**
         * @brief clears the display
         */
        void clear();

        /**
         * @brief displays the string on the 7 didigt led display
         * 
         * str cannot be longer then 7 chars
         * 
         * @param str 
         */
        void display_string(String str);

        /**
         * @brief initializes the display
         *  wakes it up
         *  clears it
         *  sets the brigthness to the intensity value asociated with the object
         * 
         */
        void init();

    private:
        int data_in_pin;
        int length_of_number(int number);
        int clk_pin;
        int load_pin; // called CS on the MAX 721 board
        int intensity = 8;
        LedControl lc;
};

#endif