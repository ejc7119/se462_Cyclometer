/*
 * Cyclometer_Distance_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Cyclometer_Distance_State.h"

ICyclometer_State* Cyclometer_Distance_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode){
		return new Cyclometer_Duration_State(settings);
	} else if(set){
		return new Cyclometer_Wheel_Size_State(settings);
	} else if(mode_start_stop_held){
		// Reset trip values
		return new Cyclometer_Distance_State(settings);
	} else if(mode_start_stop_set_held){
		return new Cyclometer_Reset_State(settings);
	} else {
		return new Cyclometer_Distance_State(settings);
	}
}
