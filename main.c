#include "PCA9685.h"
#include <stdio.h>
#include "DEV_Config.h"
#include <stdlib.h>
#include "motor.h"
#include <pigpio.h>
#include <unistd.h>

#define PWR_OUT 4 // power for button
#define PWR_IN 27 // 



int main(int argc, char *argv[]){

    if (gpioInitialise() < 0){
        return -1;
    }

    if (DEV_ModuleInit()){
        return -1;
    }

    gpioSetMode(PWR_OUT, PI_OUTPUT);
	gpioSetMode(PWR_IN, PI_INPUT);

    sleep(0.5);

    // initialize the motor
    motorInit();

    // variables to keep track of the speed, initially we want to run at a hundred percent
	int speed = 100;

    // test run for motor
    // let the motor run forward and slow down gradually by 15% in 2 second intervals
	while (speed >= 25) { // motor stops when speed is less than 25% approximately
		forward(speed, FORWARD);
		sleep(2);
		speed -= 15;
	}

	


    // program finished, clean up 
	motorStop();
	gpioTerminate();
	DEV_ModuleExit();
}


