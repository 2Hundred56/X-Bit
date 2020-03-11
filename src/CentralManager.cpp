/*
 * CentralManager.cpp
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#include "CentralManager.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "RenderTarget.h"
#include "IntVector.h"
#include "RenderData.h"
#include "GraphicsManager.h"
#include <iostream>
void CentralManager::AddObject(GameObject *object) {
	objects.insert(object);
	object->RegisterManager(this);
}

void CentralManager::GameUpdate() {
	for (auto it = objects.begin(); it!=objects.end(); it++) {
		(*it)->InitialUpdate();
	}
	for (auto it = objects.begin(); it!=objects.end(); it++) {
			(*it)->ResolveMovement();
		}
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
	target->Initialize(IntVector(300, 300), IntVector(camera.w, camera.h));
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
	objects=std::set<GameObject*, go_compare>();
	collision = new CollisionManager();
	graphics = new GraphicsManager();
}

void CentralManager::RenderTexture(Texture* tex, Vector pos, RenderData data) {
	IntVector draw = IntVector(pos-Vector(camera.x, camera.y));
	graphics->RenderTexture(tex, draw, data);
}

void CentralManager::RenderTexture(Texture *tex, Vector pos) {
	RenderTexture(tex, pos, RenderData());
}
