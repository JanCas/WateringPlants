#include "ConfigView.hpp"

ConfigView::ConfigView(String identifier, LedMatrix *lm){
    this->identifier = identifier;
    this->lm = lm;
}

button_val ConfigView::view_function(AnalogButton *ab, int &number){
    // Serial.println("I was here 3");
    lm->display_string(identifier);
    lm->display_integer(number);

    // Serial.println(identifier);
    // Serial.println(number);

    button_val ab_reading = ab->read_button();
    delay(500);
    while(true){

        ab_reading = ab->read_button();
        //Serial.println(ab->to_string(ab_reading));

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