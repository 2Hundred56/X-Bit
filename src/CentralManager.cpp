/* CentralManager.cpp - created on Apr 29, 2020
 */

#include "CentralManager.h"
#include "Constants.h"
#include "RenderLayer.h"
#include "Camera.h"
#include "Timer.h"
#include "SDL2/SDL.h"
#include "SDLTarget.h"
#include "IntVector.h"
#include "Rect.h"
#include <iostream>
CentralManager::CentralManager() {
	timer = new Timer();
	renderLayers = std::vector<RenderLayer*>();
	cameras = std::vector<Camera*>();
	overflow = 0;
	Camera* tc = new Camera(this, Rect(0,0,1,1));
	SDLTarget* st = new SDLTarget();
	st->Initialize(IntVector(576, 576));
	tc->SetTarget(st);
	cameras.push_back(tc);
}

bool CentralManager::Update() {
	float dt = timer->Mark();
	overflow+=dt;
	if (overflow<(1/FPS_CAP)) return true;
	//std::cout<<1.0f/overflow<<"\n"<<std::flush;
	overflow=0;
	SDL_Event e;
	SDL_PumpEvents();
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			return false;
		}
	}
	for (auto it = cameras.begin(); it!=cameras.end(); it++) (*it)->Ready();
	for (auto it = cameras.begin(); it!=cameras.end(); it++) (*it)->Snap();
	return true;
}

float CentralManager::PixelsPerUnit() {
	return PIXELSPERUNIT;
}

void CentralManager::Initialize() {
	timer->Mark();
}

void CentralManager::End() {
}

std::vector<RenderLayer*> CentralManager::RenderLayers() {
	return renderLayers;
}
