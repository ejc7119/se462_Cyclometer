/*
 * Display_Distance_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Display_Distance_State.h"

IDisplay_State* Display_Distance_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode){
		display->set_state(DURATION);
		return new Display_Duration_State(settings,display);
	} else if(set){
		display->set_state(WHEEL_SIZE);
		return new Display_Wheel_Size_State(settings,display);
	} else if(mode_start_stop_set_held){
		display->set_state(SPEED_SCALE);
		return new Display_Speed_Scale_State(settings,display);
	} else {
		return new Display_Distance_State(settings,display);
	}
}

