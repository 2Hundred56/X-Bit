/*
 * TestHandle.h
 *
 *  Created on: Dec 3, 2019
 *      Author: triforce
 */

#ifndef TESTHANDLE_H_
#define TESTHANDLE_H_

#include "CollisionTerms.h"

class TestHandle : public CollisionHandle {
public:
	TestHandle(Vector p, Shape* s, int sf = 0, int tf = 1);
	Shape* GetShape();
	Vector GetPos();
	void CollisionCallback(CollisionResult collision);
protected:
	Shape* shape;
	Vector pos;
};

#endif /* TESTHANDLE_H_ */
