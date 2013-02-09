/*
 * Cyclometer_Reset_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_RESET_STATE_H_
#define CYCLOMETER_RESET_STATE_H_
#include "ICyclometer_State.h"

class Cyclometer_Reset_State: public ICyclometer_State {
public:
	Cyclometer_Reset_State(int ws, bool ss):
		ICyclometer_State(ws, ss) {}
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int);
};

#endif /* CYCLOMETER_RESET_STATE_H_ */
