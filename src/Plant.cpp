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
    lm->clear();
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
}

void Plant::init(){
    Serial.println("Calibrating the water Sensor");
    delay(10000);
    wh->calibrate();
    wp->set_power(70);
}

void Plant::set_motor_power(int power){
    wp->set_power(power);
}

void Plant::set_display_brightness(int brightness){
    lm->set_brightness(brightness);
}

void Plant::set_min_moisture_pct(int min_moisture_pct){
    this->min_moisture_pct = pct_validator(min_moisture_pct);
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
    while(true){
        button_val bv = config_views[index_of_config_view].view_function(ab, config_numbers[index_of_config_view]);
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
        if (config_views.size()-1 == index_of_config_view){
            index_of_config_view = 0;
            return;
        }
        index_of_config_view++;
        return;
    } else if(bv == LEFT){
        if (index_of_config_view == 0){
            index_of_config_view = config_views.size() -1;
            return;
        }
        index_of_config_view--;
        return;
    }
}

void Plant::set_config_views(){
    String possible_configs[] = {"H PC", "L PC"};
    for(String possible_config : possible_configs){
        ConfigView cv(possible_config, lm);
        config_views.push_back(cv);
    }

    config_numbers[0] = max_moisture_pct;
    config_numbers[1] = min_moisture_pct;
    
}