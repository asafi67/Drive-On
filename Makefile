

HW=linesensors

# compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g -I.  

# libs
LIBS= -l pthread -l pigpio -l rt -lm
DEPS=

OBJ= $(HW).o DEV_Config.o PCA9685.o dev_hardware_i2c.o sysfs_gpio.o  motor.o #dev_hardware_SPI.o

USELIB= USE_DEV_LIB
DEBUG = -D $(USELIB)
CFLAGS += $(DEBUG)
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(HW): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm *.o $(HW)

run: $(HW)
	./$(HW)

