/*
 * TestObject.h
 *
 *  Created on: Mar 9, 2020
 *      Author: triforce
 */

#ifndef TESTOBJECT_H_
#define TESTOBJECT_H_

#include "GameObject.h"
class Texture;
class Vector;
class TestObject : public GameObject {
public:
	TestObject(int size, Vector pos);
	virtual void Render();
private:
	Texture* texture;
	Vector position;
};


#endif /* TESTOBJECT_H_ */
