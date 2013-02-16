/*
 * Cyclometer_Duration_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Cyclometer_Duration_State.h"

ICyclometer_State* Cyclometer_Duration_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	if(mode){
		display->set_state(AVERAGE);
		return new Cyclometer_Average_Speed_State(settings,calculations,display);
	} else if (start_stop){
		if(settings->is_manual_mode()){
			if(calculations->is_calculating()){
				calculations->stop_calculations();
			} else {
				calculations->start_calculations();
			}
		}
		return new Cyclometer_Duration_State(settings,calculations,display);
	} else if(mode_start_stop_held){
		calculations->reset();
		return new Cyclometer_Duration_State(settings,calculations,display);
	} else if(mode_start_stop_set_held){
		calculations->full_reset();
		display->set_state(SPEED_SCALE);
		return new Cyclometer_Speed_Scale_State(settings,calculations,display);
	} else {
		return new Cyclometer_Duration_State(settings,calculations,display);
	}
}
