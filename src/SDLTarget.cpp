/*
 * SDLTarget.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: triforce
 */

#include "SDLTarget.h"
#include "IntVector.h"
#include "SDL2/SDL.h"
#include <iostream>
void SDLTarget::Render(unsigned int *data, IntVector texture) {
	if (width!=texture.x || height!=texture.y) {
		width=texture.x;
		height=texture.y;
		SDL_DestroyTexture(screenTexture);
		screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
				SDL_TEXTUREACCESS_STATIC, width, height);
	}
	SDL_UpdateTexture(screenTexture, NULL, data, width * sizeof(unsigned int));
}

void SDLTarget::Flip() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void SDLTarget::BeginGraphics() {
}

void SDLTarget::Initialize(IntVector screen, IntVector texture) {
	width=texture.x;
	height=texture.y;
	screenWidth=screen.x;
	screenHeight=screen.y;
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) throw(1);
	window = SDL_CreateWindow("Generic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if( window == NULL ) throw("3");
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) throw(true);
	screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
	if (screenTexture==NULL) throw(1.2);
}

SDLTarget::SDLTarget()  { // @suppress("Class members should be properly initialized")
}

SDLTarget::~SDLTarget() {
}

void SDLTarget::CloseGraphics() {
	SDL_DestroyTexture(screenTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
