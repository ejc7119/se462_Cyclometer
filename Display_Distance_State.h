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

class Display_Distance_State: public IDisplay_State {
public:
	Display_Distance_State(Settings* set):
		IDisplay_State(set) {}

	virtual IDisplay_State* determine_state(int,int,int,int,int,int);
};
#endif /* DISPLAY_DISTANCE_STATE_H_ */
