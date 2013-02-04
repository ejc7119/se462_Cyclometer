/*
 * ICyclometer_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef ICYCLOMETER_STATE_H_
#define ICYCLOMETER_STATE_H_

class ICyclometer_State {
public:
	ICyclometer_State() {};
	~ICyclometer_State() {};
	virtual ICyclometer_State* determine_state() = 0;
};
#endif /* ICYCLOMETER_STATE_H_ */
