/*
 * Cyclometer_Average_Speed_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_AVERAGE_SPEED_STATE_H_
#define CYCLOMETER_AVERAGE_SPEED_STATE_H_

#include "ICyclometer_State.h"
#include "Settings.h"
#include "Cyclometer_Distance_State.h"
#include "Cyclometer_Speed_Scale_State.h"

class Cyclometer_Average_Speed_State: public ICyclometer_State {
public:
	Cyclometer_Average_Speed_State(Settings* set,Calculations* calc):
		ICyclometer_State(set,calc) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_AVERAGE_SPEED_STATE_H_ */
