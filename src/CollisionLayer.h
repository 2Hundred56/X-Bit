/*
 * CollisionLayer.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef COLLISIONLAYER_H_
#define COLLISIONLAYER_H_
#include <vector>
class Vector;
class CollisionHandle;
class CollisionLayer {
public:
	virtual ~CollisionLayer() {

	}
	virtual std::vector<CollisionHandle*> Check(CollisionHandle* handle, Vector sweep) = 0;
};

#endif /* COLLISIONLAYER_H_ */
