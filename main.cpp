#include "mbed.h"
#include "arm_book_lib.h"



DigitalIn lightDetector(BUTTON1); // ldr day sensor

DigitalOut led(LED1);


bool ledstate; // is the light on 



//  main() runs in its own thread in the OS
int main(){

    while(true){

    if (lightDetector==ON && ledstate==ON){ // is the light on and it is sunny out
        led= OFF;
        ledstate = OFF;


    }
    if (ledstate ==ON){
        led= ON;
    }

    }

}
