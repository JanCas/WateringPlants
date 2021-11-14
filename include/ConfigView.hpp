#ifndef BA223B3F_3C6D_4691_B560_892642543191
#define BA223B3F_3C6D_4691_B560_892642543191
#include <Arduino.h>
#include "LedMatrix.hpp"
#include "AnalogButton.hpp"

/**
 * @brief Class for displaying config settings on the MAX7219 display
 * the first 4 digits are for the identifier
 * the last 4 digits for the config number 
 */
class ConfigView{
    protected:
        String identifier;
        LedMatrix *lm;
        
    public:
        button_val view_function(AnalogButton *ab, int &number);
        ConfigView(String identifier, LedMatrix *lm);
};

#endif /* BA223B3F_3C6D_4691_B560_892642543191 */
