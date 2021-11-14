#ifndef WATERPUMP_H_
#define WATERPUMP_H_

class WaterPump{
    private:
        int power_pin;
        int direction_pin;
        static const int HIGH_POWER = 255;
        static const int LOW_POWER = 0;
        int power = 75;
        int pct_to_power(int pct);
    public:
        WaterPump(int power_pin, int direction_pin);
        void turn_on();
        void shut_off();
        void set_power(int power);    
        int get_power();    
};

#endif