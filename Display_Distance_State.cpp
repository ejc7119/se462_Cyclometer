/*
 * Display_Distance_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Display_Distance_State.h"

IDisplay_State* Display_Distance_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode){
		return new Display_Duration_State(settings,calculations);
	} else if(set){
		return new Display_Wheel_Size_State(settings,calculations);
	} else if(mode_start_stop_set_held){
		return new Display_Reset_State(settings,calculations);
	} else {
		return new Display_Distance_State(settings,calculations);
	}
}
