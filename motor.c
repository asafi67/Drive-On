#include "motor.h"


// initialize the motor
void motorInit()
{
	PCA9685_Init(0x40);
	PCA9685_SetPWMFreq(100);
}	

// run the motor with given speed and direction
void forward(int speed, int direction) {
	if (speed > 100) {
		speed = 100;
	}

	PCA9685_SetPwmDutyCycle(PWMA, speed);
    PCA9685_SetPwmDutyCycle(PWMB, speed);
    
	if (direction == FORWARD) {
		
		PCA9685_SetLevel(AIN1, 0);
    	PCA9685_SetLevel(AIN2, 1);

		PCA9685_SetLevel(BIN1, 0);
    	PCA9685_SetLevel(BIN2, 1);
	} else {
		PCA9685_SetLevel(AIN1, 1);
    	PCA9685_SetLevel(AIN2, 0);

		PCA9685_SetLevel(BIN1, 1);
    	PCA9685_SetLevel(BIN2, 0);
	}
}

// stop the motor
void motorStop() {

	PCA9685_SetPwmDutyCycle(PWMA, 0);
    PCA9685_SetPwmDutyCycle(PWMB, 0);
    
}

void turnLeft(void){
    PCA9685_SetPwmDutyCycle(PWMA, 0);
}

void turnRight(void){
    PCA9685_SetPwmDutyCycle(PWMB, 0);
}