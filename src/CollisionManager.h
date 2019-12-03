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
class CollisionManager {
public:
	CollisionManager();
	virtual ~CollisionManager();
	std::vector<CollisionResult> CheckCollisionsStatic(CollisionHandle* handle);
	CollisionResult CheckCollisionsSweep(CollisionHandle* handle, Vector sweep);
	CollisionResult CheckCollision(CollisionHandle* h1, CollisionHandle* h2, Vector velocity);
};

#endif /* COLLISIONMANAGER_H_ */
