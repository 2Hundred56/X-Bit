/*
 * CentralManager.h
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#ifndef CENTRALMANAGER_H_
#define CENTRALMANAGER_H_
#include <set>
#include "Rect.h"
#include <vector>
#include "GameObject.h"
#include "InputTerms.h"
class GraphicsManager;
class CollisionManager;
class RenderTarget;
class RenderLayer;
class Texture;
class RenderData;
class InputSource;
class CentralManager {
public:
	CentralManager();
	virtual ~CentralManager();
	float InputX(unsigned char playerNo);
	float InputY(unsigned char playerNo);
	InputState InputA(unsigned char playerNo);
	InputState InputB(unsigned char playerNo);
	InputState InputC(unsigned char playerNo);
	InputState InputD(unsigned char playerNo);
	void AddObject(GameObject* object);
	void GameUpdate(float deltaTime);
	void BeginGraphics();
	void CloseGraphics();
	void Initialize();
	void RenderTexture(Texture* tex, Vector pos, RenderData data);
	void RenderTexture(Texture* tex, Vector pos);
	Rect GetCamera() const {
		return camera;
	}

	float DT() const {
		return dt;
	}

	CollisionManager* collision = 0;
	GraphicsManager* graphics = 0;
	RenderTarget* target = 0;
//protected:
	Rect camera;
	std::set<GameObject*, go_compare> objects;
	std::vector<RenderLayer*> layers;
	std::vector<InputSource*> inputSources;
	float dt;
	int nextID = 0;

};


#endif /* CENTRALMANAGER_H_ */
