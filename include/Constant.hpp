#ifndef BD2DB6F4_43DB_401E_955B_B60900F2DF95
#define BD2DB6F4_43DB_401E_955B_B60900F2DF95

#include "ConfigView.hpp"
#include "BoardButtonsEnum.hpp"

class Constant{
    private:
        int number;
        ConfigView *cv;
        String name;

    public:
        Constant(int number, ConfigView *cv, String name);
        button_val call();    
        int get_number;
        
};

#endif /* BD2DB6F4_43DB_401E_955B_B60900F2DF95 */
