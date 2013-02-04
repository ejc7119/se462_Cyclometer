/*
 * IDisplay_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef IDISPLAY_STATE_H_
#define IDISPLAY_STATE_H_

class IDisplay_State {
public:
	IDisplay_State() {};
	~IDisplay_State() {};
	virtual IDisplay_State* determine_state() = 0;
};

#endif /* IDISPLAY_STATE_H_ */
