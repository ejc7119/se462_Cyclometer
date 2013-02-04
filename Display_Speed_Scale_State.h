/*
 * Display_Speed_Scale_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef DISPLAY_SPEED_SCALE_STATE_H_
#define DISPLAY_SPEED_SCALE_STATE_H_
#include "IDisplay_State.h"
class Display_Speed_Scale_State: public IDisplay_State {
public:
	virtual IDisplay_State* determine_state();
};

#endif /* DISPLAY_SPEED_SCALE_STATE_H_ */
