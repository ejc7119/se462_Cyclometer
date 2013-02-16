/*
 * Inputs.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include "Controller.h"
#include <pthread.h>
#include "Cregister.h"
#include "register.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#define SET_BUTTON 1
#define START_BUTTON 2
#define MODE_BUTTON 4
#define MODE_START_BUTTON 6
#define ALL_BUTTON 7
#define CONT_PRESS_MODE 10
#define INVALID_KEY	0

using namespace std;
class Inputs {
private:
	Controller* controller;
	void get_inputs();
	int whichButtonPressed();
	uintptr_t cntrlHandle;
	Cregister HWregister;
public:
	Inputs(Controller*);
	static void* run_inputs(void*);
};

#endif /* INPUTS_H_ */
