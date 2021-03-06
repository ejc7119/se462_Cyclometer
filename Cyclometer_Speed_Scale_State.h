/*
 * Cyclometer_Speed_Scale_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_SPEED_SCALE_STATE_H_
#define CYCLOMETER_SPEED_SCALE_STATE_H_
#include "ICyclometer_State.h"
#include "Settings.h"
#include "Cyclometer_Wheel_Size_State.h"
#include "Display.h"

class Cyclometer_Speed_Scale_State: public ICyclometer_State {
public:
	Cyclometer_Speed_Scale_State(Settings* set,Calculations* calc,Display* dis):
		ICyclometer_State(set,calc,dis) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_SPEED_SCALE_STATE_H_ */
