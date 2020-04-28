/*
 * CollisionManager.cpp
 *
 *  Created on: Nov 25, 2019
 *      Author: triforce
 */

#include "CollisionManager.h"
#include "BroadPhase.h"
#include "BruteForce.h"
#include <algorithm>
CollisionManager::CollisionManager(CentralManager* m) : manager(m) {
	broadPhase=new BruteForce();
	layers.push_back(broadPhase);
}

CollisionManager::~CollisionManager() {
	// TODO Auto-generated destructor stub
}

CollisionResult CollisionManager::CheckCollisionSweep(CollisionHandle *h1,
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
		Projection proj1 = s1->Proj(axis)+Projection(projection(p1, axis),projection(p1, axis));
		Projection proj2 = s2->Proj(axis)+Projection(projection(p2, axis),projection(p2, axis));

		if (v==0) {
			if ((proj1.max+proj2.max-proj1.min-proj2.min)>(std::max(proj1.max, proj2.max)-std::min(proj1.min, proj2.min))) continue;
			else {
				return CollisionResult();
			}
		}
		hasrun=true;
		firstTOI=(proj2.min-proj1.max)/v;
		lastTOI=(proj2.max-proj1.min)/v;

		if (lastTOI<maxTOI) {
			maxTOI=lastTOI;
		}
		if (firstTOI>minTOI) {
			minTOI=firstTOI;
			p = (proj1.max+v*firstTOI);
			lastAxis=axis;
		}
		if (maxTOI<0 || minTOI>1 || maxTOI<minTOI) {
			return CollisionResult();
		}
	}
	if (!hasrun) return CollisionResult();
	return CollisionResult(h2, -lastAxis, minTOI, p);
}

std::vector<CollisionResult> CollisionManager::CheckCollisionsSweep(
		CollisionHandle *h, Vector sweep) {
	std::vector<CollisionResult> results = std::vector<CollisionResult>();
	for (auto jt = layers.begin(); jt!=layers.end(); jt++) {
		std::vector<CollisionHandle*> checks = (*jt)->Check(h, sweep);
		for (auto it=checks.begin(); it<checks.end(); it++) {
			if (!(h->GetSortingFlag()&(*it)->GetSortingFlag())) continue;
			CollisionResult r = CheckCollisionSweep(h, (*it), sweep);
			if (r.collision) results.push_back(r);
		}
	}
	std::sort(results.begin(), results.end());
	return results;

}

void CollisionManager::RegisterHandle(CollisionHandle *handle) {
	broadPhase->Insert(handle);
}

void CollisionManager::RemoveHandle(CollisionHandle *handle) {
	broadPhase->Remove(handle);
}

std::vector<CollisionResult> CollisionManager::CheckCollisionsStatic(
		CollisionHandle *h) {
	std::vector<CollisionResult> results = std::vector<CollisionResult>();
	for (auto jt = layers.begin(); jt!=layers.end(); jt++) {
		std::vector<CollisionHandle*> checks = (*jt)->Check(h, Vector(0, 0));
		for (auto it=checks.begin(); it<checks.end(); it++) {
			if (!(h->GetSortingFlag()&(*it)->GetSortingFlag())) continue;
			CollisionResult r = CheckCollisionStatic(h, (*it));
			if (r.collision) results.push_back(r);
		}
	}
	std::sort(results.begin(), results.end());
	return results;
}

CollisionResult CollisionManager::CheckCollisionStatic(CollisionHandle *h1,
		CollisionHandle *h2) {
	Shape* s1 = h1->GetShape();
	Vector p1 = h1->GetPos();
	Shape* s2 = h2->GetShape();
	Vector p2 = h2->GetPos();
	std::set<Vector> axes, axes2;
	axes = s1->Axes(s2, p2-p1);
	axes2 = s2->Axes(s1, p1-p2);
	float maxP = 0;
	Vector axis;
	Vector maxAxis;
	for (auto it=axes.begin(); it!=axes.end(); it++) {
		axis=*it;
		Projection proj1 = s1->Proj(axis)+Projection(projection(p1, axis),projection(p1, axis));
		Projection proj2 = s2->Proj(axis)+Projection(projection(p2, axis),projection(p2, axis));
		float p = (proj1.max+proj2.max-proj1.min-proj2.min)-(std::max(proj1.max, proj2.max)-std::min(proj1.min, proj2.min));
		if (p<=0) return CollisionResult();
		if (p>maxP) {
			maxP=p;
			maxAxis=axis;
		}
	}
	return CollisionResult(h2, maxAxis, maxP, 0);

}
