/*
 * Sensor.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include "Calculations.h"

class Sensor{
private:
	Calculations* calculations;
public:
	Sensor(Calculations* calc):
		calculations(calc){}
	void pulse_interrupt();
};

#endif /* SENSOR_H_ */
