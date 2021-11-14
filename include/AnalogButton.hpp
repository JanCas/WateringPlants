#ifndef B84C562A_05BE_48AB_B8D9_04BA5D9EBDBA
#define B84C562A_05BE_48AB_B8D9_04BA5D9EBDBA
#include "BoardButtonsEnum.hpp"
#include "Arduino.h"

class AnalogButton{
    private:
        int pin_number;
    public:
        AnalogButton(int pin_number);
        button_val read_button();
        static String to_string(button_val val);
};

#endif /* B84C562A_05BE_48AB_B8D9_04BA5D9EBDBA */
