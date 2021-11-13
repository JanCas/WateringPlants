#include "AnalogButton.hpp"

AnalogButton::AnalogButton(int pin_number) {
    this->pin_number = pin_number;
    pinMode(pin_number, INPUT);
}

button_val AnalogButton::read_button() {
    int val = analogRead(pin_number);

    if (val > -10 && val < 10){
        return TOP;
    }
    if (val > 300 && val < 350){
        return BOTTOM;
    }
    if (val > 100 && val < 200){
        return LEFT;
    }
    if (val > 500 && val < 600){
        return RIGHT;
    }
    if (val > 700 && val < 800){
        return SELECT;
    }
}
