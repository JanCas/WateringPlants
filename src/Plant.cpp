#include "Plant.hpp"


Plant::Plant(int min_moisture_pct, int max_moisture_pct, WaterPump *wp, LedMatrix *lm, WaterHumiditySensor *wh, AnalogButton *ab) {
    set_min_moisture_pct(min_moisture_pct);
    set_max_moisture_pct(max_moisture_pct);
    this->wp = wp;
    this->lm = lm;
    this->wh = wh;
    this->ab = ab;    
}

void Plant::step() {
    int water_moisture_pct = wh->pct_between_bounds(wh->read_current());

    button_val bv = ab->read_button();
    // Serial.println(ab->to_string(bv));
    if (bv == SELECT){
        // Serial.println("I was here");
        config_views_show();
    }


    lm->clear();
    lm->display_integer(100);
/*
    lm->display_integer(water_moisture_pct);

    if (water_moisture_pct < min_moisture_pct){
        wp->turn_on();
        while(wh->pct_between_bounds(wh->read_current()) < max_moisture_pct){
            delay(500);
            lm->clear();
            lm->display_integer(wh->pct_between_bounds(wh->read_current()));
        }
        wp->shut_off();
    }
    */
}

void Plant::init(){
    // Serial.println("Calibrating the water Sensor");
    //set_config_views();
    //delay(10000);
    //wh->calibrate();
    //wp->set_power(70);
}

void Plant::set_motor_power(int power){
    wp->set_power(power);
}

void Plant::set_display_brightness(int brightness){
    lm->set_brightness(brightness);
}

void Plant::set_min_moisture_pct(int min_moisture_pct){
    min_moisture_pct = pct_validator(min_moisture_pct);

    ConfigView cv("H Pc", lm);

    constant[MAX_MOISTURE_IND] = Constant(cv, min_moisture_pct);

}

void Plant::set_max_moisture_pct(int max_moisture_pct){
    this->max_moisture_pct = pct_validator(max_moisture_pct);
}

int Plant::pct_validator(int pct){
    if (pct < 0) return 0;
    if (pct > 100) return 100;

    return pct;
}

void Plant::config_views_show(){
    // Serial.println("I WAS HERE 2");
    while(true){
        lm->clear();
        button_val bv = constant[index_of_config_view].cv.view_function(ab, constant[index_of_config_view].value);
        if (bv == SELECT){
            break;
        }
        set_index_of_config_view(bv);
        lm->clear();
        delay(100);
    }
}

void Plant::set_index_of_config_view(button_val bv){
    if (bv == RIGHT){
        if (max_config_screens-1 == index_of_config_view){
            index_of_config_view = 0;
            return;
        }
        index_of_config_view++;
        return;
    } else if(bv == LEFT){
        if (index_of_config_view == 0){
            index_of_config_view = max_config_screens-1;
            return;
        }
        index_of_config_view--;
        return;
    }
}