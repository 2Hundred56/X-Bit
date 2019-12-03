/*
 * CollisionTerms.h
 *
 *  Created on: Nov 25, 2019
 *      Author: triforce
 */

#ifndef COLLISIONTERMS_H_
#define COLLISIONTERMS_H_
#include "Vector.h"
#include "Rect.h"
#include <vector>
#include <iostream>
#include <set>

class Projection {
public:
	float min;
	float max;
	Projection(float x, float y) : min(x), max(y) {

	}
};
class Shape {
public:
	virtual ~Shape() {

	}
	virtual std::set<Vector> Axes (Shape*, Vector) = 0;
	virtual Projection Proj(Vector axis) = 0;
	virtual Rect ContainBox() = 0;
};
class AABB : public Shape {
public:
	AABB(float hw, float hh);
	virtual std::set<Vector> Axes (Shape*, Vector);
	virtual Projection Proj(Vector axis);
	virtual Rect ContainBox();
protected:
	float hw, hh;
};
class CollisionHandle {
public:
	virtual ~CollisionHandle() {

	}
	int cflag = 0;
	int ID = 0;
	virtual Shape* GetShape() = 0;
	virtual Vector GetPos() = 0;
	virtual Rect GetRect();
};
class CollisionResult {
public:
	bool collision = false;
	CollisionResult() { // @suppress("Class members should be properly initialized")
		collision = false;
	}

	CollisionHandle* other;
	Vector normal;
	float toi;
	float point;
	CollisionResult(CollisionHandle* other, Vector normal, float toi, float point) : other(other), normal(normal), toi(toi), point(point), collision(true){
	}
};

#endif /* COLLISIONTERMS_H_ */
