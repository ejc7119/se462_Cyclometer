/*
 * Display_Wheel_Size_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef DISPLAY_WHEEL_SIZE_STATE_H_
#define DISPLAY_WHEEL_SIZE_STATE_H_
#include "IDisplay_State.h"
#include "Settings.h"
#include "Display_Distance_State.h"
#include "Display_Average_Speed_State.h"
#include "Display.h"

class Display_Wheel_Size_State: public IDisplay_State {
public:
	Display_Wheel_Size_State(Settings* set,Display* dis):
		IDisplay_State(set,dis) {}

	virtual IDisplay_State* determine_state(int,int,int,int,int,int);
};
#endif /* DISPLAY_WHEEL_SIZE_STATE_H_ */
