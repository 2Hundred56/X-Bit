/*
 * TestHandle.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: triforce
 */

#include "TestHandle.h"
#include <iostream>
Shape* TestHandle::GetShape() {
	return shape;
}

Vector TestHandle::GetPos() {
	return pos;
}

TestHandle::TestHandle(Vector p, Shape *s, int sf, int tf) : pos (p), shape(s) {
	sortingFlag = sf;
	typeFlag = tf;
}

void TestHandle::CollisionCallback(CollisionResult collision) {
	std::cout<<"TEST reports collision at t="<<collision.toi<<". Normal: "<<collision.normal<<". Point: "<<collision.point<<"\n"<<std::flush;
}
