/*
 * Controller.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Controller.h"

Controller::Controller(){
	settings = new Settings();

	cyclometer_current = new Cyclometer_Reset_State(settings);
	display_current = new Display_Reset_State(settings);
}
void Controller::receive_event(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	// Determine the next cyclometer and display state
	ICyclometer_State* new_cyclometer_state = cyclometer_current->determine_state(mode,start_stop,set,mode_start_stop_set_held,mode_held,mode_start_stop_held);
	IDisplay_State* new_display_state = display_current->determine_state(mode,start_stop,set,mode_start_stop_set_held,mode_held,mode_start_stop_held);

	// Delete the pointers to the current states
	delete cyclometer_current;
	delete display_current;

	// Set the current states to the new states
	cyclometer_current = new_cyclometer_state;
	display_current = new_display_state;
}
