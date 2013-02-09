/*
 * Inputs.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Inputs.h"

Inputs::Inputs(Controller* con){
	controller = con;
}

/*
 * Method for retrieving button inputs from the hardware
 */
void Inputs::get_inputs(){
	while(1){

		// If MODE press
		controller->receive_event(1,0,0,0,0,0);

		// If START/STOP press
		controller->receive_event(0,1,0,0,0,0);

		// If SET press
		controller->receive_event(0,0,1,0,0,0);

		// If MODE_START/STOP_SET Held press
		controller->receive_event(0,0,0,1,0,0);

		// If MODE Held press
		controller->receive_event(0,0,0,0,1,0);

		// If MODE_START/STOP Held press
		controller->receive_event(0,0,0,0,0,1);
	}
}
