#ifndef WATERPUMP_H_
#define WATERPUMP_H_

class WaterPump{
    private:
        int power_pin;
        int direction_pin;
        static const HIGH_POWER = 255;
        static const LOW_POWER = 0;
    public:
        WaterPump(int power_pin, int direction_pin);
        void turn_on();
        void shut_off();        
};

#endif