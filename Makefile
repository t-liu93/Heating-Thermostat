PROJECT_DIR = $(shell pwd)
ARDUINO_HOME = extern/Arduino
SERIAL_PORT = /dev/ttyS3g

include extern/Esp8266-Arduino-Makefile/espXArduino.mk

prepare:
	-git submodule update --init --recursive
	-cd $(PROJECT_DIR)/$(ARDUINO_HOME)/tools && ./get.py