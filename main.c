#include "PCA9685.h"
#include <stdio.h>
#include "DEV_Config.h"
#include <stdlib.h>
#include "assignment3.h"
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
		motorRun(speed, FORWARD);
		sleep(2);
		speed -= 15;
	}

	// once the speed is less then 15% and the motor stops running, we stop the motor
	// and reset the speed back to 100% and do the reverse this time
	motorStop();
	sleep(1);




    // program finished, clean up 
	motorStop();
	gpioTerminate();
	DEV_ModuleExit();
}



// initialize the motor
void motorInit()
{
	PCA9685_Init(0x40);
	PCA9685_SetPWMFreq(100);
}	

// run the motor with given speed and direction
void motorRun(int speed, int direction) {
	if (speed > 100) {
		speed = 100;
	}

	PCA9685_SetPwmDutyCycle(PWMA, speed);
	if (direction == FORWARD) {
		PCA9685_SetLevel(AIN1, 0);
    		PCA9685_SetLevel(AIN2, 1);
	} else {
		PCA9685_SetLevel(AIN1, 1);
    		PCA9685_SetLevel(AIN2, 0);
	}
}


// stop the motor
void motorStop() {

	PCA9685_SetPwmDutyCycle(PWMA, 0);
}