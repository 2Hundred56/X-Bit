/*
 * WASDSource.h
 *
 *  Created on: Mar 18, 2020
 *      Author: triforce
 */

#ifndef WASDSOURCE_H_
#define WASDSOURCE_H_

#include "InputSource.h"

class WASDSource: public InputSource {
public:
	virtual float InputX() { return X; }
	virtual float InputY() { return Y; }
	virtual InputState InputA() { return A; }
	virtual InputState InputB() { return B; }
	virtual InputState InputC() { return C; }
	virtual InputState InputD() { return D; }
	virtual void Update();
protected:
	float X=0;
	float Y=0;
	InputState A = OFF;
	InputState B = OFF;
	InputState C = OFF;
	InputState D = OFF;
};

#endif /* WASDSOURCE_H_ */
