/*
 * Display_Wheel_Size_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef DISPLAY_WHEEL_SIZE_STATE_H_
#define DISPLAY_WHEEL_SIZE_STATE_H_
#include "IDisplay_State.h"
class Display_Wheel_Size_State: public IDisplay_State {
public:
	virtual IDisplay_State* determine_state();
};
#endif /* DISPLAY_WHEEL_SIZE_STATE_H_ */
