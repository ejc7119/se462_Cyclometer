/*
 * Calculations.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Calculations.h"

Calculations::Calculations(Settings* set,Sensor* sens){
	settings = set;
	sensor = sens;
	Calculations::prevCnt = 0;
	currTime = 0;
	timeDiff = 0;
	Calculations::prevTime = 0;
}

double Calculations::get_average_speed(){
	if(duration != 0){
		average_speed = (distance/duration)*3600;
	} else {
		average_speed = 0;
	}
	cout << "Average Speed:" << average_speed << endl;
	if(!settings->is_km_speed_scale()){
		return average_speed*(0.62137);
	}
	return average_speed;
}

double Calculations::get_current_speed(){
	cout << "Current Speed:" << current_speed << endl;
	if(!settings->is_km_speed_scale()){
		return current_speed*(0.62137);
	}
	return current_speed;
}

double Calculations::get_distance(){
	cout << "Distance: "<< distance << endl;
	if(!settings->is_km_speed_scale()){
		return distance*(0.62137);
	}
	return distance;
}

double Calculations::get_duration(){
	cout << duration << endl;
	return duration;
}

int Calculations::get_wheel_size(){
	return settings->get_wheel_size();
}

void Calculations::receive_pulse(int pulseCnt){
	if(pulseCnt != prevCnt)
	{
		currTime = clock();

		timeDiff = (currTime - prevTime)/ 1000;

		prevTime = currTime;
		prevCnt = pulseCnt;

		if(calculating || settings->is_manual_mode() == false){
			duration += timeDiff/1000;

			distance += (double)settings->get_wheel_size()/100000;
		}
	}
}

void Calculations::full_reset(){
	average_speed = 0;
	distance = 0;
	duration = 0;
	settings->reset();
	calculating = false;
}

void Calculations::reset(){
	average_speed = 0;
	distance = 0;
	duration = 0;
}

void* Calculations::run_calculations(void* arg){
	Calculations* self = (Calculations*)arg;
	while(1){
		self->receive_pulse(self->sensor->get_count());
		if(self->calculating || self->settings->is_manual_mode() == false){

			self->current_speed = (((double)self->settings->get_wheel_size()/(double)self->timeDiff))*(36);
		}
		usleep(500);
	}
	return NULL;
}

void Calculations::start_calculations(){
	calculating = true;
}

void Calculations::stop_calculations(){
	calculating = false;
}

bool Calculations::is_calculating(){
	return calculating;
}

bool Calculations::is_km_speed_scale(){
	return settings->is_km_speed_scale();
}

