#ifndef MOTOR_H
#define MOTOR_H

#include "PCA9685.h"
#include "DEV_Config.h"

#define PWMA PCA_CHANNEL_0
#define AIN1 PCA_CHANNEL_1
#define AIN2 PCA_CHANNEL_2
#define BIN1 PCA_CHANNEL_3
#define BIN2 PCA_CHANNEL_4
#define PWMB PCA_CHANNEL_5
#define FORWARD	0
#define REVERSE 1

void motorInit(void);
void forward(int speed, int direction);
void motorStop(void);
void turnLeft(void);
void turnRight(void);

#endif
