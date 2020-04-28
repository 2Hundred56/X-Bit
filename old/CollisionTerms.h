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

const unsigned char GROUND = 1;
const unsigned char HITBOX = 2;
const unsigned char GRENEMY = 4;
//------------------------------
const unsigned char SOLID = 1;

class Projection {
public:
	float min;
	float max;
	Projection(float x, float y) : min(x), max(y) {

	}
};
Projection operator +(Projection p1, Projection p2);
class Shape {
public:
	virtual ~Shape() {

	}
	virtual std::set<Vector> Axes (Shape*, Vector) = 0;
	virtual Projection Proj(Vector axis) = 0;
	virtual Rect ContainBox() = 0;
};
class LineSegment : public Shape{
public:
	LineSegment (Vector slope);
	virtual std::set<Vector> Axes (Shape*, Vector);
	virtual Projection Proj(Vector axis);
	virtual Rect ContainBox();
protected:
	Vector p, normal, along;
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
class CollisionResult;
class CollisionHandle {
public:
	virtual ~CollisionHandle() {

	}
	virtual Shape* GetShape() = 0;
	virtual Vector GetPos() = 0;
	virtual void CollisionCallback(CollisionResult result);
	virtual unsigned char GetSortingFlag() = 0;
	virtual unsigned char GetTypeFlag() = 0;
};
class RequestHandle : public CollisionHandle{
public:
	RequestHandle(Shape* s, Vector p, unsigned char f) : shape(s), position (p), flag(f) {

	}
	virtual Shape* GetShape() {
		return shape;
	}
	virtual Vector GetPos() {
		return position;
	}
	unsigned char GetTypeFlag() {
		return 0;
	}
	Shape* shape;
	Vector position;
	unsigned char flag;
};
class GameObject;
class AttachedHandle : public CollisionHandle {
public:
	AttachedHandle(Shape* s, GameObject* o, unsigned char sf, unsigned char tf) : shape(s), parent (o) {
		sortingFlag=sf;
		typeFlag=tf;
	}
	virtual Shape* GetShape() {
		return shape;
	}
	virtual Vector GetPos();
	virtual unsigned char GetSortingFlag() {
		return sortingFlag;
	}
	virtual unsigned char GetTypeFlag() {
		return typeFlag;
	}
	Shape* shape;
	GameObject* parent;
	unsigned char sortingFlag;
	unsigned char typeFlag;
};
class Tile;
class TileHandle : public CollisionHandle {
	//TODO: Finish this
public:
	TileHandle(Tile* t, Vector p);
	virtual Shape* GetShape();
	virtual Vector GetPos() {
		return pos;
	}
	virtual unsigned char GetSortingFlag();
	virtual unsigned char GetTypeFlag();
protected:
	Tile* tile;
	Vector pos;
};
class CollisionResult {
public:
	bool collision = false;
	CollisionResult() { // @suppress("Class members should be properly initialized")
		collision = false;
	}

	CollisionHandle* other = 0;
	Vector normal;
	float toi;
	float point;
	CollisionResult(CollisionHandle* other, Vector normal, float toi, float point) : other(other), normal(normal), toi(toi), point(point), collision(true){
	}
};

bool operator <(CollisionResult r1, CollisionResult r2);

inline void CollisionHandle::CollisionCallback(CollisionResult result) {
}

#endif /* COLLISIONTERMS_H_ */
