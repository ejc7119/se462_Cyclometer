/*
 * Inputs.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include "Controller.h"

class Inputs {
private:
	Controller* controller;
public:
	Inputs(Controller*);
	void get_inputs();
};

#endif /* INPUTS_H_ */
