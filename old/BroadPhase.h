/*
 * BroadPhase.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef BROADPHASE_H_
#define BROADPHASE_H_
#include "CollisionLayer.h"

class BroadPhase : public CollisionLayer {
public:
	BroadPhase() : CollisionLayer() {

	}
	virtual void Insert(CollisionHandle* handle) = 0;
	virtual void Remove(CollisionHandle* handle) = 0;
};

#endif /* BROADPHASE_H_ */
