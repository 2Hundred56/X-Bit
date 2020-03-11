/*
 * main.cpp
 *
 *  Created on: Nov 25, 2019
 *      Author: triforce
 */

#include "CentralManager.h"
#include "SDLTarget.h"
#include "SDL2/SDL.h"
#include "Rect.h"
#include "CollisionManager.h"
#include "TestObject.h"
#include "TestHandle.h"
#include "ResourceManager.h"
#include "SMB1/Mario.h"
#include <iostream>
int main(int argc, char* args[]) {
	CentralManager* manager = new CentralManager();
	ResourceManager* rsrc = new ResourceManager();
	//Tileset* set = rsrc->LoadTileset("convert/smb1-ground-tileset.xbit");
	float i=200;
	manager->camera=Rect(0, 0, i, i);
	manager->target=new SDLTarget();
	manager->Initialize();
	TestHandle* t1 = new TestHandle(Vector(-1, -4), new AABB(1, 1));
	TestHandle* t2 = new TestHandle(Vector(100, 200), new AABB(100, 32));
	SMB1::Mario* to = new SMB1::Mario();
	manager->AddObject(to);
	manager->collision->RegisterHandle(t2);
	CollisionResult r = manager->collision->CheckCollisionSweep(t1, t2, Vector(1, 1));
	if (r.collision) {
		std::cout<<r.normal<<"\n"<<std::flush;
		std::cout<<r.toi<<"\n"<<std::flush;
		std::cout<<r.point<<"\n"<<std::flush;
	}
	SDL_Event e;
	bool quit = false;
	while (!quit){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			/*if (e.type == SDL_KEYDOWN){
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN){
				quit = true;
			}*/
		}
		manager->GameUpdate();
	}
	manager->CloseGraphics();
	return 0;

}
