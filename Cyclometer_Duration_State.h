/*
 * Cyclometer_Duration_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_DURATION_STATE_H_
#define CYCLOMETER_DURATION_STATE_H_
#include "ICyclometer_State.h"
#include "Settings.h"
#include "Cyclometer_Average_Speed_State.h"
#include "Cyclometer_Speed_Scale_State.h"
#include "Display.h"

class Cyclometer_Duration_State: public ICyclometer_State{
public:
	Cyclometer_Duration_State(Settings* set,Calculations* calc,Display* dis):
		ICyclometer_State(set,calc,dis) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_DURATION_STATE_H_ */
