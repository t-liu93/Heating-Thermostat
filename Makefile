PROJECT_DIR = $(shell pwd)
ARDUINO_HOME = $(PROJECT_DIR)/extern/Arduino
BUILD_OUT = $(PROJECT_DIR)/build
SERIAL_PORT = /dev/ttyS3
GLOBAL_USER_LIBDIR = $(PROJECT_DIR)/extern

USER_LIBS += pubsubclient hal


include extern/Esp8266-Arduino-Makefile/espXArduino.mk

prepare:
	-git submodule update --init --recursive
	-cd $(PROJECT_DIR)/$(ARDUINO_HOME)/tools && ./get.py