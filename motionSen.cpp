#include "mbed.h"
#include "arm_book_lib.h"

/*
Motion Sensor SubSystem:
 1. If light on and no motion within X seconds turn Light on/off
 2. Adjust X with code
 3. Turn Light on when Motion detected (Feature)
 4. Dim Lights if not motion within X seconds till off (Feature)
 5. Disable Motion Sensor 
*/

// init  %%%%%%%%% change nucleo pins
// --input

DigitalIn motionSen(PB_3); // pir, motion sensor
// --output
// decelartion of global variables
int timeOut; // the time  before motion sensor needs rettrigering 
bool motionSenEnable = true;
// decelartion of  functions

void isMotion(bool &lightState);

void isMotion(bool &lightState){
    if(motionSenEnable){
        if(motionSen){
         //   printf("Motion is on, light is on\n");

            lightState = true;
        } 
        else{
            lightState = false;

        } }  }

void inputInit(){ // setup buttons 
    motionSen.mode(PullUp);}