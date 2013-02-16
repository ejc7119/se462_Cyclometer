/*
 * Display.h
 *
 *  Created on: Feb 13, 2013
 *      Author: ejc7119
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "Calculations.h"
#include "pthread.h"
#include "Cregister.h"
#include "register.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

#define AVERAGE 1
#define DISTANCE 2
#define DURATION 3
#define RESET 4
#define SPEED_SCALE 5
#define WHEEL_SIZE 6

class Display{
private:
	Calculations* calculations;
	int state;
	Cregister HWregister;
	uintptr_t cntrlHandle_A;
	uintptr_t cntrlHandle_B;
	int unit, tenth, isFraction;
	int unit_c, tenth_c, isFraction_c, displayelapsedTime;
	int displayAvSpeed, displayCurrentSpeed, displayelapsedDistance, displayWheel;
	int port_u,port_t, portCurr_u,portCurr_t;

	void breakDatainDigits(float data);
	void breakCurrSpeed(float data);
	void selectSegment(int digit, int point, int displayPos);
	void displayAvgSpeed(float data);
	void displayTripDistance(float data);
	void displayCurrSpeed(float data);
	void displayTripTime(float data);
	void displayWheelSize(int data);
	void updateDisplay(int unitDigit, int tenthDigit, int isFraction, int port_u, int port_t, int isTime);
    void displayTripTimeMin(float data);
    void displayTripTimeSec(float data);
    void displayTripDistanceUpper(float data);
    void displayTripDistancelower(float data);
    void displayWheelSizeUpper(int data);
    void displayWheelSizelower(int data);
    void displaySpeedScale();

public:
	Display(Calculations*);
	static void* run_display(void*);
	void set_state(int);
};
#endif /* DISPLAY_H_ */
