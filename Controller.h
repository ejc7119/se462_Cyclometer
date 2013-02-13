/*
 * Controller.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "ICyclometer_State.h"
#include "IDisplay_State.h"
#include "Cyclometer_Reset_State.h"
#include "Display_Reset_State.h"
#include "Settings.h"
#include "pthread.h"
#include "Calculations.h"

class Controller {

private:
	ICyclometer_State* cyclometer_current;
	IDisplay_State* display_current;
	Settings* settings;
	Calculations* calculations;
	pthread_t display_thread;
public:
	Controller(Settings*,Calculations*);
	void receive_event(int,int,int,int,int,int);
};
#endif /* CONTROLLER_H_ */
