/*
 * Settings.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: ejc7119
 */

#include "Settings.h"

Settings::Settings(){
	wheel_size = 210;
	km_speed_scale = true;
	manual_mode = true;
}

int Settings::get_wheel_size(){
	return wheel_size;
}

bool Settings::is_km_speed_scale(){
	return km_speed_scale;
}

bool Settings::is_manual_mode(){
	return manual_mode;
}

bool Settings::is_initializing(){
	return initializing;
}

void Settings::increase_wheel_size(){
	if(wheel_size < 220){
		wheel_size++;
	} else {
		wheel_size = 190;
	}
}

void Settings::switch_speed_scale(){
	if(km_speed_scale){
		km_speed_scale = false;
	} else {
		km_speed_scale = true;
	}
}

void Settings::switch_manual_mode(){
	if(manual_mode){
		manual_mode = false;
	} else {
		manual_mode = true;
	}
}

void Settings::switch_initializing(){
	if(initializing){
		initializing = false;
	} else {
		initializing = true;
	}
}

void Settings::reset(){
	km_speed_scale = true;
	wheel_size = 210;
}
