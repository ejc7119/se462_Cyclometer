/*
 * Display_Average_Speed_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef DISPLAY_AVERAGE_SPEED_STATE_H_
#define DISPLAY_AVERAGE_SPEED_STATE_H_
#include "IDisplay_State.h"
class Display_Average_Speed_State: public IDisplay_State {
public:
	Display_Average_Speed_State() {}

	virtual IDisplay_State* determine_state(int,int,int,int,int,int);
};

#endif /* DISPLAY_AVERAGE_SPEED_STATE_H_ */
