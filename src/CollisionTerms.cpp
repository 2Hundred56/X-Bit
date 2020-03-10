/*
 * CollisionTerms.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: triforce
 */
#include "CollisionTerms.h"
#include "GameObject.h"
Projection operator +(Projection p1, Projection p2) {
	return Projection(p1.min + p2.min, p1.max + p2.max);
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

LineSegment::LineSegment(Vector slope) {
	p = slope / 2;
	if (p.x<0) p=-p;
	along=normalize(p * 2);
	normal=Vector(along.y, -along.x);
	if (normal.x<0) normal=-normal;
}

std::set<Vector> LineSegment::Axes(Shape*, Vector vector) {
	return std::set<Vector>({normal, along});
}

Projection LineSegment::Proj(Vector axis) {
	float proj1=projection(-p, axis);
	float proj2=projection(p, axis);
	return Projection(std::min(proj1, proj2), std::max(proj1, proj2));
}

Rect LineSegment::ContainBox() {
	return Rect(-p.x, std::min(-p.y, p.y), p.x, std::max(-p.y, p.y));
}

Vector AttachedHandle::GetPos() {
	return parent->position;
}

bool operator <(CollisionResult r1, CollisionResult r2) {
	return r1.toi < r2.toi;
}
