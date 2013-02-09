/*
 * Cyclometer_Duration_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_DURATION_STATE_H_
#define CYCLOMETER_DURATION_STATE_H_
#include "ICyclometer_State.h"
class Cyclometer_Duration_State: public ICyclometer_State{
public:
	Cyclometer_Duration_State(int ws, bool ss):
		ICyclometer_State(ws, ss) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_DURATION_STATE_H_ */
