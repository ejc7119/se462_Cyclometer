/*
 * Controller.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Controller.h"

Controller::Controller(Settings* set,Calculations* calc,Display* dis){
	settings = set;
	calculations = calc;
	display = dis;

	cyclometer_current = new Cyclometer_Speed_Scale_State(settings,calculations,display);
}
void Controller::receive_event(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	// Determine the next cyclometer and display state
	ICyclometer_State* new_cyclometer_state = cyclometer_current->determine_state(mode,start_stop,set,mode_start_stop_set_held,mode_held,mode_start_stop_held);

	// Delete the pointers to the current states
	delete cyclometer_current;

	// Set the current states to the new states
	cyclometer_current = new_cyclometer_state;

}
