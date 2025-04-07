#include "mbed.h"
#include "arm_book_lib.h"

/*
Heat Sensor:
 1. If temp here then x(*c) turn Heater off <==
 2. Adjust (*c)                             <==
 3. Disable Sensor  %% just need to be able to externally modify var
*/

// init  %%%%%%%%% change nucleo pins
// --input
AnalogIn tempSen(PA_4); // thermistor used to meausre temp


// decelartion of global variables

float tempSet = 0.2; 
bool tempSenEnable = true;


// decelartion of  functions
void isHot(bool &heatState);

void isHot(bool &heatState){
    if(tempSenEnable){
        float tempRead = tempSen.read();
      //  printf("temp reading: %.2f\n", tempRead);

        if(tempRead >= tempSet){
            if(heatState){
                heatState = false;
            }
            
        }
    }
}

