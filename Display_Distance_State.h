/*
 * Display_Distance_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef DISPLAY_DISTANCE_STATE_H_
#define DISPLAY_DISTANCE_STATE_H_
#include "IDisplay_State.h"
#include "Settings.h"
#include "Display_Duration_State.h"
#include "Display_Wheel_Size_State.h"
#include "Display_Speed_Scale_State.h"
#include "Display.h"

class Display_Distance_State: public IDisplay_State {
public:
	Display_Distance_State(Settings* set,Display* dis):
		IDisplay_State(set,dis) {}

	virtual IDisplay_State* determine_state(int,int,int,int,int,int);
};
#endif /* DISPLAY_DISTANCE_STATE_H_ */
