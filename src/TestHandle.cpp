/*
 * TestHandle.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: triforce
 */

#include "TestHandle.h"
#include <iostream>
TestHandle::TestHandle(Vector p, Shape *s) : pos (p), shape(s) {
}

Shape* TestHandle::GetShape() {
	return shape;
}

Vector TestHandle::GetPos() {
	return pos;
}
void TestHandle::CollisionCallback(CollisionResult collision) {
	std::cout<<ID<<" reports collision at t="<<collision.toi<<". Normal: "<<collision.normal<<". Point: "<<collision.point<<"\n"<<std::flush;
}
