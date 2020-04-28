/*
 * EventSystem.h
 *
 *  Created on: Mar 18, 2020
 *      Author: triforce
 */

#ifndef INPUTSOURCE_H_
#define INPUTSOURCE_H_
#include "InputTerms.h"
class InputSource {
public:
	InputSource() {

	}
	virtual ~InputSource() {

	}
	virtual float InputX() = 0;
	virtual float InputY() = 0;
	virtual InputState InputA() = 0;
	virtual InputState InputB() = 0;
	virtual InputState InputC() = 0;
	virtual InputState InputD() = 0;
	virtual void Update() {

	}
};

#endif /* INPUTSOURCE_H_ */
