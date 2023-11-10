#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include "PCA9685.h"
#include "DEV_Config.h"

#define PWMA PCA_CHANNEL_0
#define AIN1 PCA_CHANNEL_1
#define AIN2 PCA_CHANNEL_2
#define FORWARD	0
#define REVERSE 1

void motorInit(void);
void motorRun(int speed, int direction);
void motorStop(void);
void turnLeft(void);
void turnRight(void);