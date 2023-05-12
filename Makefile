# *****************************************************
# Makefile for AirWatcher
# *****************************************************
 
# *****************************************************
# Variables to control Makefile operation:
# *****************************************************

# The compiler: gcc for C program, define as g++ for C++ 
CC = g++

# Compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS = -g #-Wall

# File's path
CONTROLLER_DIRS ?= ./controller
MODEL_DIRS ?= ./model
VIEW_DIRS ?= ./view

# Find cpp files in subdirectories
SOURCES := $(shell find . -name '*.cpp')

# Find headers
CONTROLLER_H := $(shell find $(CONTROLLER_DIRS) -name *.h)
MODEL_H := $(shell find $(MODEL_DIRS) -name *.h)
VIEW_H := $(shell find $(VIEW_DIRS) -name *.h)

# *****************************************************
# Targets needed to bring the executable up to date:
# *****************************************************

# We create the first target in our makefile i.e. the executable main (or the test).
# -o option flag write the build output to an output file
main: main.o
	$(CC) $(CFLAGS) -o main $(SOURCES)

# Generate objects
CONTROLLER_OBJECT := $(addsuffix .o,$(basename $(CONTROLLER_H)))
MODEL_OBJECT := $(addsuffix .o,$(basename $(MODEL_H)))
VIEW_OBJECT := $(addsuffix .o,$(basename $(VIEW_H)))



# Our next target will be to generate object files:

# To generate main.o
# The -c flag says to generate the object file
main.o: ./view/main.cpp $(VIEW_H) $(CONTROLLER_H) $(MODEL_H)
	$(CC) $(CFLAGS) -c ./view/main.cpp 



Attributes.o: ./model/Attributes.cpp
	$(CC) $(CFLAGS) -c Attributes.cpp

Cleaner.o: ./model/Cleaner.cpp
	$(CC) $(CFLAGS) -c Cleaner.cpp

Database.o: ./model/Database.cpp
	$(CC) $(CFLAGS) -c Database.cpp

GovernmentAgency.o: ./model/GovernmentAgency.cpp
	$(CC) $(CFLAGS) -c GovernmentAgency.cpp

Measurement.o: ./model/Measurement.cpp
	$(CC) $(CFLAGS) -c Measurement.cpp

PrivateUser.o: ./model/PrivateUser.cpp
	$(CC) $(CFLAGS) -c PrivateUser.cpp

Provider.o: ./model/Provider.cpp
	$(CC) $(CFLAGS) -c Provider.cpp

Sensor.o: ./model/Sensor.cpp
	$(CC) $(CFLAGS) -c Sensor.cpp

User.o: ./model/User.cpp
	$(CC) $(CFLAGS) -c User.cpp

ControllerPrivateUser.o: ./controller/ControllerPrivateUser.cpp
	$(CC) $(CFLAGS) -c ControllerPrivateUser.cpp

History.o: ./controller/History.cpp
	$(CC) $(CFLAGS) -c History.cpp

# ****************************************************
# Cleaning files
clean:
	rm -rf *.o


