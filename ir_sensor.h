#ifndef IR_SENSOR
#define IR_SENSOR

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>



//Function declarations

int exportGPIO(int pin);
int setGPIO(int pin, const char* direction);
int readGPIO(int pin);
void handleSensor(void* args);

#endif // IR_SENSOR
