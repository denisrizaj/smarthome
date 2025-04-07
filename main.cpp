#include "mbed.h"
#include "arm_book_lib.h"

// #include "motionSen.cpp"
#include "tempSen.h"
#include "daySen.h"
#include "motionSen.h"






// init
// --input
DigitalIn hSwitch(PE_13); // house switch
// --output
DigitalOut lightSource(PF_15);
DigitalOut heatSource(PF_13);
DigitalOut testSource(LED2);

// serial mointor
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);


// decelartion of global variables
// --output varibles
bool lightState = true; // are the lights on or off
bool heatState = true; // are the lights on or off

// deceleration of functions
// -- test function
void motionTest(); //  daySen function
int main(){


    //inputInit();
    lightSource = ON;
    heatState = true;

    hSwitch.mode(PullDown);

    while(true){
        if(hSwitch){
            lightState = true;
        }

        isHot(heatState);

        isMotion(lightState); // if no motion detected turn LED OFF
        isDay(lightState); // if not day and light on 

        if(lightState){
            lightSource = ON;
            }
        else{
            lightSource = OFF;
        }
        if(heatState){
            heatSource = ON;

        }
        else{
            heatSource = OFF;
        }

        
    }
}

// implementation of functions

    
void motionTest(){
    testSource = ON;
    isMotion(lightState);
    if(lightState){
        lightSource = ON;
    }
    else{
        lightSource = OFF;
        }
    
}
// use this function to read from a file and modifyf certain variables
// void userFile(); here is my code what is causing this issue

/*   
void dayTest(){
 isDay(lightState);
    if(lightState){
        lightSource = ON;
    }
    else{
        lightSource = OFF;
    } }
    
    
    
        void motionTest(){
    testSource = ON;
    isMotion(lightState);
    if(lightState){
        lightState = ON;
    }
    else{
        lightState = OFF;
        }
    
    
    
    
    void hotTest(){
    testSource = ON;
    isHot(heatState);
    if(heatState){
        heatSource = ON;
    }
    else{
        heatSource = OFF;
        }



    
}
    
    
    
    */