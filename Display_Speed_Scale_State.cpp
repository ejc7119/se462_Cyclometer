/*
 * Display_Speed_Scale_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Display_Speed_Scale_State.h"

IDisplay_State* Display_Speed_Scale_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(set){
		return new Display_Wheel_Size_State(settings,calculations);
	} else {
		return new Display_Speed_Scale_State(settings,calculations);
	}
}

void Display_Speed_Scale_State::update_display(){

}
