/*
 * CollisionManager.h
 *
 *  Created on: Nov 25, 2019
 *      Author: triforce
 */

#ifndef COLLISIONMANAGER_H_
#define COLLISIONMANAGER_H_
#include "CollisionTerms.h"
#include <vector>
class BroadPhase;
class CollisionManager {
public:
	CollisionManager();
	virtual ~CollisionManager();
	std::vector<CollisionResult> CheckCollisionsStatic(CollisionHandle* h);
	std::vector<CollisionResult> CheckCollisionsSweep(CollisionHandle* h, Vector sweep);
	CollisionResult CheckCollisionSweep(CollisionHandle* h1, CollisionHandle*  h2, Vector sweep);
	void RegisterHandle(CollisionHandle* handle);
	void RemoveHandle(CollisionHandle* handle);
protected:
	std::vector<BroadPhase*> broadPhases;
};

#endif /* COLLISIONMANAGER_H_ */
