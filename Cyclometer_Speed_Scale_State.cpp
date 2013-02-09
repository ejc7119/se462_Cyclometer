/*
 * Cyclometer_Speed_Scale_State.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Cyclometer_Speed_Scale_State.h"

ICyclometer_State* Cyclometer_Speed_Scale_State::determine_state(int mode,int start_stop,int set,int mode_start_stop_set_held,int mode_held, int mode_start_stop_held){
	return new Cyclometer_Speed_Scale_State(settings);
}
