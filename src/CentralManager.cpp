/*
 * CentralManager.cpp
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#include "CentralManager.h"
#include "GameObject.h"
#include "PhysicsManager.h"
#include "CollisionManager.h"
#include "RenderTarget.h"
#include "IntVector.h"
#include "GraphicsManager.h"
void CentralManager::AddObject(GameObject *object) {
	objects.insert(object);
}

void CentralManager::GameUpdate() {
	for (auto it = objects.begin(); it!=objects.end(); it++) {
		(*it)->InitialUpdate();
	}
	for (auto it = objects.begin(); it!=objects.end(); it++) {
		(*it)->ResolveMovement();
	}
	physics->Update();
	for (auto it = objects.begin(); it!=objects.end(); it++) {
		(*it)->Update();
	}
	graphics->Prepare(IntVector(camera.w, camera.h));
	for (auto it = objects.begin(); it!=objects.end(); it++) {
		(*it)->Render();
	}
	target->Render(graphics->Process(), IntVector(camera.w, camera.h));
	target->Flip();
	for (auto it = objects.begin(); it!=objects.end(); it++) {
		(*it)->LateUpdate();
	}
}

void CentralManager::BeginGraphics() {
	target->Initialize(IntVector(576, 576), IntVector(camera.w, camera.h));
	target->BeginGraphics();
}

void CentralManager::CloseGraphics() {
	target->CloseGraphics();
	delete target;
}

CentralManager::CentralManager() {
}

CentralManager::~CentralManager() {
}

void CentralManager::Initialize() {
	BeginGraphics();
	objects=std::set<GameObject*>();
	physics = new PhysicsManager();
	collision = new CollisionManager();
	graphics = new GraphicsManager();
}
