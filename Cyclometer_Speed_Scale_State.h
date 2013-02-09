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

class Cyclometer_Speed_Scale_State: public ICyclometer_State {
public:
	Cyclometer_Speed_Scale_State(Settings* set):
		ICyclometer_State(set) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_SPEED_SCALE_STATE_H_ */
