#include "IRsensor.h"

void *readIRSensor(void *arg) {
	struct sensorStruct *sensor = (struct sensorStruct *) arg;
       		
	
	while(!terminate) {
		*(sensor->sensorValue) = gpioRead(sensor->sensorPin);

	}
	return NULL;
}

