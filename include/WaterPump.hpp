#ifndef WATERPUMP_H_
#define WATERPUMP_H_

class WaterPump{
    private:
        int pin_number;
    public:
        WaterPump(int pin_number);
        void turn_on();
        void shut_off();        
};

#endif