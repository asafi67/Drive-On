#ifndef IR_SENSOR
#define IR_SENSOR

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


#define IR_SENSOR_FRONT 17
#define IR_SENSOR_LEFT 24
#define IR_SENSOR_RIGHT 25

//Function declarations

int exportGPIO(int pin);
int setGPIO(int pin, const char* direction);
int readGPIO(int pin);
void* handleSensor(void* args);

#endif // IR_SENSOR
