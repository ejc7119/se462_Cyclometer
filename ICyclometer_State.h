/*
 * ICyclometer_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef ICYCLOMETER_STATE_H_
#define ICYCLOMETER_STATE_H_

class ICyclometer_State {
protected:
	int wheel_size;
	bool km_speed_scale;
public:
	// Parameters: Wheel Size, Speed Scale (true = km)
	ICyclometer_State(int ws,bool ss):
		wheel_size(ws), km_speed_scale(ss) {}
	virtual ~ICyclometer_State() {};
	// Parameters: Mode, Start/Stop, Set, Mode_Start/Stop_Set Held, Mode Held, Mode_Start/Stop Held
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int) = 0;
};
#endif /* ICYCLOMETER_STATE_H_ */
