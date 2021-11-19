#include "EEPROM_util.h"

void clear(){
    for (int i = 0; i < EEPROM.length(); i++) {
        EEPROM.write(i, CLEAR_VAL);
    }   
}