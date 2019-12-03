/*
 * CollisionTerms.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: triforce
 */
#include "CollisionTerms.h"
Projection operator +(Projection p1, Projection p2) {
	return Projection(p1.min + p2.min, p1.max + p2.max);
}
Rect CollisionHandle::GetRect() {
	return GetShape()->ContainBox()+GetPos();
}
Projection AABB::Proj(Vector axis) {
	float a = projection(Vector(-hw, -hh), axis);
	float b = projection(Vector(hw, -hh), axis);
	float c = projection(Vector(-hw, hh), axis);
	float d = projection(Vector(hw, hh), axis);
	return Projection(std::min(std::min(a, b), std::min(c, d)), std::max(std::max(a, b), std::max(c, d)));
}

Rect AABB::ContainBox() {
	return Rect(-hw, -hh, hw*2, hh*2);
}

AABB::AABB(float hw, float hh) : hw(hw), hh(hh){
}

std::set<Vector> AABB::Axes(Shape*, Vector vector) {
	std::set<Vector> axes;
	axes.insert(Vector(0, 1));
	axes.insert(Vector(1, 0));
	return axes;
}
