/*
 * Cregister.h
 *
 *  Created on: Feb 9, 2013
 *      Author: hxk9609
 */

#ifndef CREGISTER_H_
#define CREGISTER_H_
#include "register.h"
class Cregister{
public:
	int getIOaccess();
	int configurePort();
	uintptr_t memoryMapPortB();
	uintptr_t memoryMapPortA();
	uintptr_t memoryMapPortC();
	int readreg(uintptr_t ctrlHandle);
	void writeRegister(uintptr_t ctrlHandle, int val);
};

#endif /* CREGISTER_H_ */

