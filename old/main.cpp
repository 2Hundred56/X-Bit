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
#include "TileLayer.h"
#include "CollisionManager.h"
#include "TestObject.h"
#include "Tile.h"
#include "TestHandle.h"
#include "ResourceManager.h"
#include "SMB1/Mario.h"
#include <iostream>
#include "TestLine.h"
#include <chrono>
int main(int argc, char* args[]) {
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::duration<float> fsec;
	CentralManager* manager = new CentralManager();
	ResourceManager* rsrc = new ResourceManager();
	//rsrc->ConvertTileset("convert/smb1-ground-tileset.bmp","convert/smb1-ground-tileset.xbit",16);
	manager->target=new SDLTarget();
	manager->Initialize();
	//	TestHandle* t1 = new TestHandle(Vector(-1, -4), new AABB(1, 1));
	//	TestHandle* t2 = new TestHandle(Vector(100, 200), new AABB(100, 32));
	SMB1::Mario* to = new SMB1::Mario();
	to->position=Vector(32,0);
	manager->AddObject(to);
	TestLine* line = new TestLine(32, 32);
	line->position = Vector(64, 64);

	manager->AddObject(line);

	TileLayer* l = new TileLayer(manager, 200, 200, 16, 16);

	manager->layers.push_back(l);
	manager->collision->layers.push_back(l);

	Tileset* ts = rsrc->LoadTileset("convert/smb1-ground-tileset.xbit");

	l->tilesets.push_back(ts);
	l->tilesetData[0+0*200]=1;
	l->tilesetData[0+1*200]=1;
	l->tilesetData[0+2*200]=1;
	l->tilesetData[0+3*200]=1;
	l->tilesetData[0+4*200]=1;
	l->tilesetData[0+5*200]=1;
	l->tilesetData[0+6*200]=1;
	l->tilesetData[0+7*200]=1;
	l->tilesetData[0+8*200]=1;
	l->tilesetData[0+9*200]=1;
	l->tilesetData[0+10*200]=1;
	l->tilesetData[1+8*200]=1;
	l->tilesetData[1+9*200]=1;
	l->tilesetData[1+10*200]=1;
	l->tilesetData[2+9*200]=1;
	l->tilesetData[2+10*200]=1;
	l->tilesetData[3+10*200]=1;
	l->tilesetData[4+10*200]=1;
	l->tilesetData[5+10*200]=1;
	l->tilesetData[6+10*200]=1;
	l->tilesetData[7+10*200]=1;
	l->tilesetData[8+10*200]=1;
	SDL_Event e;
	auto t0 = Time::now();
	auto t1 = Time::now();
	float dt;
	float overflow = 0;
	float fpsLimit = 60.0;
	bool quit = false;

	while (!quit){
		dt = ((fsec) (t1 - t0)).count();
		overflow+=dt;
		if (overflow>(1/60.0)) {
			while (SDL_PollEvent(&e)){
				if (e.type == SDL_QUIT){
					quit = true;
				}
			}
			manager->GameUpdate(1/fpsLimit);
			overflow=0;
		}
	}
	manager->CloseGraphics();
	return 0;

}
