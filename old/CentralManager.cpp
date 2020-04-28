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
#include "RenderLayer.h"
#include "WASDSource.h"
#include "GraphicsManager.h"
#include "InputSource.h"
#include <iostream>
void CentralManager::AddObject(GameObject *object) {
	object->ID=nextID;
	nextID++;
	objects.insert(object);
	object->RegisterManager(this);
	object->Initialize();
}

void CentralManager::GameUpdate(float delta) {
	dt=delta;
	for (auto it = inputSources.begin(); it!=inputSources.end(); it++) {
		(*it)->Update();
	}
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
	for (auto it = layers.begin(); it!=layers.end(); it++) {
		(*it)->Render();
	}
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
	float i=200;
	camera=Rect(0, 0, i, i);
	BeginGraphics();
	layers = std::vector<RenderLayer*>();
	objects=std::set<GameObject*, go_compare>();
	collision = new CollisionManager(this);
	graphics = new GraphicsManager();
	inputSources = std::vector<InputSource*> ();
	inputSources.push_back(new WASDSource());
}

void CentralManager::RenderTexture(Texture* tex, Vector pos, RenderData data) {
	IntVector draw = IntVector(pos-Vector(camera.x, camera.y));
	graphics->RenderTexture(tex, draw, data);
}

float CentralManager::InputX(unsigned char playerNo) {
	if (inputSources.size()<=playerNo) return 0;
	return inputSources[playerNo]->InputX();
}

float CentralManager::InputY(unsigned char playerNo) {
	if (inputSources.size()<=playerNo) return 0;
	return inputSources[playerNo]->InputY();
}

InputState CentralManager::InputA(unsigned char playerNo) {
	if (inputSources.size()<=playerNo) return OFF;
	return inputSources[playerNo]->InputA();
}

InputState CentralManager::InputB(unsigned char playerNo) {
	if (inputSources.size()<=playerNo) return OFF;
	return inputSources[playerNo]->InputB();
}

InputState CentralManager::InputC(unsigned char playerNo) {
	if (inputSources.size()<=playerNo) return OFF;
	return inputSources[playerNo]->InputC();
}

InputState CentralManager::InputD(unsigned char playerNo) {
	if (inputSources.size()<=playerNo) return OFF;
	return inputSources[playerNo]->InputD();
}

void CentralManager::RenderTexture(Texture *tex, Vector pos) {
	RenderTexture(tex, pos, RenderData());
}
