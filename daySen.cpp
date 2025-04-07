#include "mbed.h"
#include "arm_book_lib.h"

/*
Day Sensor:
 1. If Light on and it is Sun out Turn Light off  <==
 2. Adjust Light Sensitivity                      <==
 3. Disable Sensor %% just need to be able to externally modify var
*/

// init  %%%%%%%%% change nucleo pins
// --input
AnalogIn daySen(PA_0); // LDR used as light sensor


// decelartion of global variables

int setDay = 300; // user set value for daytime
bool daySenEnable = true; // does the user want to enable the sensor %%%%%% get this change this var from file


// decelartion of  functions
void isDay(bool &lightState); // main function takes a var and changes its value


// implementation of functions

/* isDay checks the using a LDR if is day time if so it turns the light of
    -- is the function Enabled
    -- store  light reading to dayRead
    -- is dayRead >= the a value we defin as day time
    -- if yes  and the light is on turn it off*/

void isDay(bool &lightState){
    // read daySenEnable
    if(daySenEnable){ // if the sensor is not disabled       
        float dayRead = daySen.read(); // store the light value

        if (dayRead >= 150){
        printf("lux 150");}
             // if the ldr value is higher then the set day value
        if (dayRead >= 250){ 
             printf("lux 250");}// if the ldr value is higher then the set day value
        if (dayRead >= 350){
             printf("lux 350");} // if the ldr value is higher then the set day value
        if (dayRead >= 500){
             printf("lux 500");} // if the ldr value is higher then the set day value
        if (dayRead >= 750){ // if the ldr value is higher then the set day value
             printf("lux 750");}
        if (dayRead >= setDay){ // if the ldr value is higher then the set day value
            printf("It is Day\n");}

            if(lightState){ // if is day and lights on
                printf("It is Day, and lights are on\n");

                lightState = false; // turn light off
            }
    }   }
    


