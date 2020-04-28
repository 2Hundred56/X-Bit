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
class CollisionLayer;
class CentralManager;
class CollisionManager {
public:
	CollisionManager(CentralManager* m);
	virtual ~CollisionManager();
	std::vector<CollisionResult> CheckCollisionsStatic(CollisionHandle* h);
	std::vector<CollisionResult> CheckCollisionsSweep(CollisionHandle* h, Vector sweep);
	CollisionResult CheckCollisionSweep(CollisionHandle* h1, CollisionHandle*  h2, Vector sweep);
	CollisionResult CheckCollisionStatic(CollisionHandle* h1, CollisionHandle* h2);
	void RegisterHandle(CollisionHandle* handle);
	void RemoveHandle(CollisionHandle* handle);
//protected:
	BroadPhase* broadPhase;
	std::vector<CollisionLayer*> layers;
	CentralManager* manager;
};

#endif /* COLLISIONMANAGER_H_ */
