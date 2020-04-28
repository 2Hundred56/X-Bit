/*
 * TestLine.h
 *
 *  Created on: Mar 25, 2020
 *      Author: triforce
 */

#ifndef TESTLINE_H_
#define TESTLINE_H_
#include "GameObject.h"
class Texture;
class CollisionHandle;
class TestLine : public GameObject{
public:
TestLine(float x, float y);
virtual void Initialize();
virtual void Update();
virtual void Render();
protected:
	Texture* t;
	Vector slope;
	CollisionHandle* h;
};

#endif /* TESTLINE_H_ */
