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

class Controller {

private:
	ICyclometer_State* cyclometer_current;
	IDisplay_State* display_current;
	Settings* settings;
	Calculations* calculations;
public:
	Controller(Settings*,Calculations*);
	void receive_event(int,int,int,int,int,int);
};
#endif /* CONTROLLER_H_ */
