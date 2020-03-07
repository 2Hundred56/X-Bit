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

LineSegment::LineSegment(Vector point1, Vector point2) {
	if (point2.x < point1.x) {
		p1=point2;
		p2=point1;
	}
	else {
		p1=point1;
		p2=point2;
	}
	along=normalize(p2-p1);
	normal=Vector(along.y, -along.x);
	if (normal.x<0) normal=-normal;
}

std::set<Vector> LineSegment::Axes(Shape*, Vector vector) {
	return std::set<Vector>({normal, along});
}

Projection LineSegment::Proj(Vector axis) {
	float proj1=projection(p1, axis);
	float proj2=projection(p2, axis);
	return Projection(std::min(proj1, proj2), std::max(proj1, proj2));
}

Rect LineSegment::ContainBox() {
	return Rect(p1.x, std::min(p1.y, p2.y), p2.x, std::max(p1.y, p2.y));
}
