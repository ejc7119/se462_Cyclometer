/*
 * Cyclometer_Speed_Scale_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Cyclometer_Speed_Scale_State.h"

ICyclometer_State* Cyclometer_Speed_Scale_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode){
		settings->switch_speed_scale();
		return new Cyclometer_Speed_Scale_State(settings,calculations);
	} else if(set){
		return new Cyclometer_Wheel_Size_State(settings,calculations);
	} else {
		return new Cyclometer_Speed_Scale_State(settings,calculations);
	}
}
