/*
 * CentralManager.h
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#ifndef CENTRALMANAGER_H_
#define CENTRALMANAGER_H_
#include "Time.h"
#include <set>
#include "Rect.h"
class GameObject;
class PhysicsManager;
class GraphicsManager;
class CollisionManager;
class RenderTarget;
class CentralManager {
public:
	CentralManager();
	virtual ~CentralManager();
	TimeDelta deltaTime();
	void AddObject(GameObject* object);
	void GameUpdate();
	void BeginGraphics();
	void CloseGraphics();
	void Initialize();
//protected:
	Rect camera;
	std::set<GameObject*> objects;
	PhysicsManager* physics = 0;
	CollisionManager* collision = 0;
	GraphicsManager* graphics = 0;
	RenderTarget* target = 0;
};


#endif /* CENTRALMANAGER_H_ */
