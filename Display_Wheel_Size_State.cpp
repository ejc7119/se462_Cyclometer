/*
 * Display_Wheel_Size_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Display_Wheel_Size_State.h"

IDisplay_State* Display_Wheel_Size_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode_held){
		return new Display_Wheel_Size_State(settings,calculations);
	} else if(set){
		if(settings->is_initializing()){
			return new Display_Average_Speed_State(settings,calculations);
		} else {
			return new Display_Distance_State(settings,calculations);
		}
	} else {
		return new Display_Wheel_Size_State(settings,calculations);
	}
}

void Display_Wheel_Size_State::update_display(){

}
