/*
 * Controller.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Controller.h"

void Controller::receive_event(){
	// Determine the next cyclometer and display state
	ICyclometer_State* new_cyclometer_state = cyclometer_current->determine_state();
	IDisplay_State* new_display_state = display_current->determine_state();

	// Delete the pointers to the current states
	delete cyclometer_current;
	delete display_current;

	// Set the current states to the new states
	cyclometer_current = new_cyclometer_state;
	display_current = new_display_state;
}
