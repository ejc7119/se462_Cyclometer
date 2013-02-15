/*
 * Cyclometer_Wheel_Size_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Cyclometer_Wheel_Size_State.h"

ICyclometer_State* Cyclometer_Wheel_Size_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode){
		settings->increase_wheel_size();
		return new Cyclometer_Wheel_Size_State(settings,calculations);
	} else if(mode_held){
		// Increase while held
		settings->increase_wheel_size();
		return new Cyclometer_Wheel_Size_State(settings,calculations);
	} else if(set){
		if(settings->is_initializing()){
			settings->switch_initializing();
			return new Cyclometer_Average_Speed_State(settings,calculations);
		} else {
			return new Cyclometer_Distance_State(settings,calculations);
		}
	} else {
		return new Cyclometer_Wheel_Size_State(settings,calculations);
	}
}
