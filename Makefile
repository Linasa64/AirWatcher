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
TESTS_DIRS ?= ./tests

# Find cpp files in subdirectories
SOURCES := $(shell find . -name '*.cpp' -not -path "$(VIEW_DIRS)/*" -not -path "$(TESTS_DIRS)/*")

MAIN_SOURCE := $(VIEW_DIRS)/AirWatcher.cpp
TEST_SOURCE :=  $(TESTS_DIRS)/TestsAirWatcher.cpp

# Find headers
CONTROLLER_H := $(shell find $(CONTROLLER_DIRS) -name *.h)
MODEL_H := $(shell find $(MODEL_DIRS) -name *.h)
VIEW_H := $(shell find $(VIEW_DIRS) -name *.h)

# Find test classes in the subdirectory tests
TESTS := $(shell find tests -name '*.cpp')

# *****************************************************
# Targets needed to bring the executable up to date:
# *****************************************************

# We create the first target in our makefile i.e. the executable main (or the test).
# -o option flag write the build output to an output file
main: main.o
	$(CC) $(CFLAGS) -o main $(SOURCES) $(MAIN_SOURCE)

# Generate objects
CONTROLLER_OBJECT := $(addsuffix .o,$(basename $(CONTROLLER_H)))
MODEL_OBJECT := $(addsuffix .o,$(basename $(MODEL_H)))
VIEW_OBJECT := $(addsuffix .o,$(basename $(VIEW_H)))

# Our next target will be to generate object files:

# To generate main.o
# The -c flag says to generate the object file
main.o: $(VIEW_DIRS)/AirWatcher.cpp $(VIEW_H) $(CONTROLLER_H) $(MODEL_H)
	$(CC) $(CFLAGS) -c $(VIEW_DIRS)/AirWatcher.cpp 

# ****************************************************
# Cleaning files
clean:
	find . -name "*.o" -type f -delete
	rm main test

# ****************************************************
# Running tests

# make test
test: TestsAirWatcher.o
	$(CC) $(CFLAGS) -o test $(SOURCES) $(TEST_SOURCE)

TestsAirWatcher: TestsAirWatcher.o $(CONTROLLER_OBJECT) $(MODEL_OBJECT) $(VIEW_OBJECT)
	$(CC) $(CFLAGS) -o TestsAirWatcher TestsAirWatcher.o $(CONTROLLER_OBJECT) $(MODEL_OBJECT) $(VIEW_OBJECT)

TestsAirWatcher.o: $(TESTS_DIRS)/TestsAirWatcher.cpp $(VIEW_H) $(CONTROLLER_H) $(MODEL_H)
	$(CC) $(CFLAGS) -c $(TESTS_DIRS)/TestsAirWatcher.cpp -o TestsAirWatcher.o