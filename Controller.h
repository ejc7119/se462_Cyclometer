/*
 * Controller.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "ICyclometer_State.h"
#include "Settings.h"
#include "pthread.h"
#include "Calculations.h"
#include "Cyclometer_Speed_Scale_State.h"
#include "Display.h"

class Controller {

private:
	ICyclometer_State* cyclometer_current;
	Settings* settings;
	Calculations* calculations;
	Display* display;
public:
	Controller(Settings*,Calculations*,Display*);
	void receive_event(int,int,int,int,int,int);
};
#endif /* CONTROLLER_H_ */
