/*
 * BruteForce.h
 *
 *  Created on: Mar 7, 2020
 *      Author: triforce
 */

#ifndef BRUTEFORCE_H_
#define BRUTEFORCE_H_

#include "BroadPhase.h"
class BruteForce : public BroadPhase {
public:
	BruteForce () : BroadPhase() {
		handles = std::vector<CollisionHandle*>();
	}
	virtual void Insert(CollisionHandle* handle) {
		handles.push_back(handle);

	}
	virtual void Remove(CollisionHandle* handle) {
		for (auto it = handles.begin(); it<handles.end(); it++) {
			if ((*it)==handle) {
				handles.erase(it);
			}
		}
	}
	virtual std::vector<CollisionHandle*> Check(CollisionHandle* handle, Vector sweep) {
		return handles;
	}
public:
	std::vector<CollisionHandle*> handles;
};



#endif /* BRUTEFORCE_H_ */
