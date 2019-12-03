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
#include "ResourceManager.h"
int main(int argc, char* args[]) {
	CentralManager* manager = new CentralManager();
	ResourceManager* rsrc = new ResourceManager();
	//Tileset* set = rsrc->LoadTileset("convert/smb1-ground-tileset.xbit");
	float i=60;
	manager->camera=Rect(0, 0, i, i);
	manager->target=new SDLTarget();
	manager->Initialize();
	SDL_Event e;
	bool quit = false;
	while (!quit){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_KEYDOWN){
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN){
				quit = true;
			}
		}
		manager->GameUpdate();
	}
	manager->CloseGraphics();
	return 0;

}
