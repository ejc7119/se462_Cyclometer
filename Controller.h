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

class Controller {

private:
	ICyclometer_State* cyclometer_current;
	IDisplay_State* display_current;
public:
	Controller();
	void receive_event();
};
#endif /* CONTROLLER_H_ */
