#include "LedMatrix.hpp"

LedMatrix::LedMatrix(int data_in_pin, int clk_pin, int load_pin) {
    this->data_in_pin = data_in_pin;
    this->clk_pin = clk_pin;
    this->load_pin = load_pin;
    lc = LedControl(data_in_pin, clk_pin, load_pin, 1);
}

void LedMatrix::shutdown(){
    lc.shutdown(0, true);
}

void LedMatrix::wake_up() {
    lc.shutdown(0, false);
}

void LedMatrix::set_brightness(int intensity){
    lc.setIntensity(0,intensity);
}

void LedMatrix::clear(){
    lc.clearDisplay(0);
}

int LedMatrix::length_of_number(int number){
    unsigned int number_of_digits = 0;
    do {
        ++number_of_digits;
        number /= 10;
    } while (number);
    return number_of_digits;
}

void LedMatrix::display_integer(int number){
    unsigned int number_length = length_of_number(number);

    int number_as_array[number_length];

    for (size_t i = 0; i < number_length; i++)
    {
        number_as_array[i] = number % 10;
        number /= 10;
    }

    for (size_t i = 0; i < number_length; i++)
    {
        lc.setDigit(0, i, (byte) number_as_array[i], false);
    }
}