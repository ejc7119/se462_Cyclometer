/*
 * Display_Average_Speed_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Display_Average_Speed_State.h"

IDisplay_State* Display_Average_Speed_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	return new Display_Average_Speed_State(settings,display);
	if(mode){
		display->set_state(DISTANCE);
		return new Display_Distance_State(settings,display);
	} else if(mode_start_stop_set_held){
		display->set_state(SPEED_SCALE);
		return new Display_Speed_Scale_State(settings,display);
	} else {
		return new Display_Average_Speed_State(settings,display);
	}
}
