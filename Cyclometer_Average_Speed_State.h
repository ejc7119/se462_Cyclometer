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
#include "Cyclometer_Reset_State.h"

class Cyclometer_Average_Speed_State: public ICyclometer_State {
public:
	Cyclometer_Average_Speed_State(Settings* set):
		ICyclometer_State(set) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_AVERAGE_SPEED_STATE_H_ */
