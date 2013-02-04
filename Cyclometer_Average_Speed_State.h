/*
 * Cyclometer_Average_Speed_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CYCLOMETER_AVERAGE_SPEED_STATE_H_
#define CYCLOMETER_AVERAGE_SPEED_STATE_H_

#include "ICyclometer_State.h"

class Cyclometer_Average_Speed_State: public ICyclometer_State {
public:
	virtual ICyclometer_State* determine_state();
};

#endif /* CYCLOMETER_AVERAGE_SPEED_STATE_H_ */
