#include "ConfigView.hpp"

ConfigView::ConfigView(String identifier, LedMatrix *lm){
    this->identifier = identifier;
    this->lm = lm;
}

button_val ConfigView::view_function(AnalogButton *ab, int &number){
    lm->display_string(identifier);
    lm->display_integer(number);

    button_val ab_reading = ab->read_button();
    while((ab_reading != RIGHT) && (ab_reading != LEFT) && (ab_reading != SELECT)){

        ab_reading = ab->read_button();
        Serial.println(ab->to_string(ab_reading));

        switch (ab_reading)
        {
        case TOP:
            number++;    
            break;
        
        case BOTTOM:
            number--;
            break;
        default:
            break;
        }

        if (ab_reading == SELECT || ab_reading == RIGHT || ab_reading == LEFT){
            break;
        }
        lm->display_integer(number);
        delay(250);
    }

    return ab_reading;
}