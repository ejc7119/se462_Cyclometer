/*
 * Cyclometer_Wheel_Size_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_WHEEL_SIZE_STATE_H_
#define CYCLOMETER_WHEEL_SIZE_STATE_H_
#include "ICyclometer_State.h"
#include "Settings.h"
#include "Cyclometer_Average_Speed_State.h"
#include "Cyclometer_Wheel_Size_State.h"
#include "Cyclometer_Distance_State.h"

class Cyclometer_Wheel_Size_State: public ICyclometer_State {
public:
	Cyclometer_Wheel_Size_State(Settings* set,Calculations* calc):
		ICyclometer_State(set,calc) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_WHEEL_SIZE_STATE_H_ */
