/*
 * CollisionManager.cpp
 *
 *  Created on: Nov 25, 2019
 *      Author: triforce
 */

#include "CollisionManager.h"

CollisionManager::CollisionManager() {
	// TODO Auto-generated constructor stub

}

CollisionManager::~CollisionManager() {
	// TODO Auto-generated destructor stub
}

CollisionResult CollisionManager::CheckCollision(CollisionHandle *h1,
		CollisionHandle *h2, Vector velocity) {
	//velocity is the velocity of h1 relative to h2
	Shape* s1 = h1->GetShape();
	Vector p1 = h1->GetPos();
	Shape* s2 = h2->GetShape();
	Vector p2 = h2->GetPos();
	std::set<Vector> axes, axes2;
	axes = s1->Axes(s2, p2-p1);
	axes2 = s2->Axes(s1, p1-p2);
	float maxTOI = 1000;
	float minTOI = -1000;
	float firstTOI, lastTOI;
	Vector lastAxis = Vector(0, 0);
	Vector axis = Vector(0, 0);
	float p = 0;
	float s = 1;
	bool hasrun=false;
	for (auto it=axes2.begin(); it!=axes2.end(); it++) {
		axes.insert(*it);
	}
	for (auto it=axes.begin(); it!=axes.end(); it++) {
		axis=*it;
		s = 1;
		if (projection(velocity, axis)<0) {
			axis=-axis;
			s = -1;
		}
		float v = projection(velocity, axis);
		if (v==0) continue;
		hasrun=true;
		Projection proj1 = s1->Proj(axis)+Projection(projection(p1, axis),projection(p1, axis));
		Projection proj2 = s2->Proj(axis)+Projection(projection(p2, axis),projection(p2, axis));
		firstTOI=(proj2.min-proj1.max)/v;
		lastTOI=(proj2.max-proj1.min)/v;
		if (lastTOI<maxTOI) {
			maxTOI=lastTOI;
		}
		if (firstTOI>minTOI) {
			minTOI=firstTOI;
			lastAxis = axis;
			p = (proj1.max+v*firstTOI)*s;
		}
		if (maxTOI<0 || minTOI>1 || maxTOI<minTOI) {
			return CollisionResult();
		}
	}
	if (!hasrun) return CollisionResult();
	return CollisionResult(h2, -lastAxis, minTOI, p);
}
