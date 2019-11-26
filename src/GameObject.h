/*
 * GameObject.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject {
public:
	virtual ~GameObject() {

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
	int ID = 0;
	int priority = 0;
	bool deletionFlag = false;
};
bool go_compare (GameObject* a, GameObject* b) {
	if (a->priority<b->priority) return true;
	if ((a->priority==b->priority) && (a->ID<b->ID)) return true;
	return false;
}
#include <type_traits>
using gocmp = std::integral_constant<decltype(&go_compare), &go_compare>;



#endif /* GAMEOBJECT_H_ */
