/*
 * GameObject.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Vector.h"
class CentralManager;
class GameObject {
public:
	virtual ~GameObject() {

	}
	virtual void Initialize() {

	}
	virtual void InitialUpdate() {

	}
	virtual void ResolveMovement() {

	}
	virtual void Update() {

	}
	virtual void Render() {

	}
	virtual void LateUpdate() {

	}
	virtual void RegisterManager(CentralManager* m) {
		manager=m;
	}
	Vector position;
	int ID = 0;
	int priority = 0;
	bool deletionFlag = false;
	CentralManager* manager;
};
struct go_compare {
	const bool operator() (GameObject* a, GameObject* b) {
		if (a->priority<b->priority) return true;
			if ((a->priority==b->priority) && (a->ID<b->ID)) return true;
			return false;
	}

};



#endif /* GAMEOBJECT_H_ */
