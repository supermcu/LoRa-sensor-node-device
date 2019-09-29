#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "../inc/main.h"
#include "../inc/MCC Drivers/mcc.h"
#include "../inc/MCC Drivers/eusart.h"
#include "../inc/MCC Drivers/adc.h"
#include "../inc/MCC Drivers/timer.h"
#include "../inc/Peripheral Drivers/battery.h"
#include "../inc/Peripheral Drivers/sht30.h"
#include "../inc/Peripheral Drivers/max44009.h"
#include "../inc/Peripheral Drivers/ds18b20.h"

char msg[30];
uint16_t adcResult;
float batteryVoltage, soilTemperature, airTemperature, airHumidity, lightness;

void setSystemStatus(bool state){
    systemStatus = state;
}

bool getSystemStatus(){
    return systemStatus;
}

void main(void){
    // initialize the device
    SYSTEM_Initialize();
    EUSART_Initialize();
    
    int i = 0;
    
    while (1){
        sprintf(msg, "i = %d\n", i);
        EUSART_SendString(msg);
        if(i == 20) setSystemStatus(WARNING);
        i++;
        SLEEP();
    }
    
}
