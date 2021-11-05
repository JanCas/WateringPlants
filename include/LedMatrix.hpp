
#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

#include "LedControl.h"

class LedMatrix{
    public:
        LedMatrix(int data_in_pin, int clk_pin, int load_pin);
        void display_integer(int number);
        void shutdown();
        void wake_up();
        void set_brightness(int intensity);
        void clear();
    private:
        int data_in_pin;
        int length_of_number(int number);
        int clk_pin;
        int load_pin; // called CS on the MAX 721 board
        LedControl lc;
};

#endif