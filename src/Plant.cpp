#include "Plant.hpp"


Plant::Plant(int min_moisture_pct, int max_moisture_pct, WaterPump *wp, LedMatrix *lm, WaterHumiditySensor *wh) {
    set_min_moisture_pct(min_moisture_pct);
    set_max_moisture_pct(max_moisture_pct);
    this->wp = wp;
    this->lm = lm;
    this->wh = wh;    
}

void Plant::step() {
    int water_moisture_pct = wh->pct_between_bounds(wh->read_current());
    lm->clear();
    lm->display_integer(water_moisture_pct);

    if (water_moisture_pct < min_moisture_pct){
        wp->turn_on();
        while(wh->pct_between_bounds(wh->read_current()) < max_moisture_pct){
            delay(500);
        }
        wp->shut_off();
    }
}

void Plant::init(){
    Serial.println("Calibrating the water Sensor");
    delay(10000);
    wh->calibrate();
    wp->set_power(25);
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