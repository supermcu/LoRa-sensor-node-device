#include "statusLed.h"
#include "main.h"

void statusLed_Inicialize(){
    NORMAL_LED_PIN = 0;
    WARNING_LED_PIN = 0;
    NORMAL_LED = 0;
    WARNING_LED = 0;
}

void swapLedState(){
    if(getSystemStatus() == NORMAL){
        WARNING_LED = 0;
        NORMAL_LED = !NORMAL_LED;
    }else{
        NORMAL_LED = 0;
        WARNING_LED = !WARNING_LED;
    }
}
