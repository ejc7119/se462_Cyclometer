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

class Inputs {
private:
	Controller* controller;
	void get_inputs();
public:
	Inputs(Controller*);
	static void* run_inputs(void*);
};

#endif /* INPUTS_H_ */
