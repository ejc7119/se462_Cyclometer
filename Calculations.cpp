/*
 * Calculations.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Calculations.h"

Calculations::Calculations(Settings* set){
	settings = set;
}

double Calculations::get_average_speed(){
	return average_speed;
}

double Calculations::get_current_speed(){
	return current_speed;
}

double Calculations::get_distance(){
	return distance;
}

double Calculations::get_duration(){
	return duration;
}

int Calculations::get_wheel_size(){
	return settings->get_wheel_size();
}

void Calculations::receive_pulse(){

}

void Calculations::full_reset(){
	average_speed = 0;
	distance = 0;
	duration = 0;
	settings->reset();
}

void Calculations::reset(){
	average_speed = 0;
	distance = 0;
	duration = 0;
}

void* Calculations::run_calculations(void*){
	return NULL;
}
