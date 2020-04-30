/*
 * SDLTarget.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#include "SDLTarget.h"
#include "Pixel.h"
#include "Texture.h"
#include "TextureScaling.h"
#include "SDL2/SDL.h"
IntVector SDLTarget::DestinationSize() {
	return size;
}
void SDLTarget::Render(Texture *tex) {
	if (!initialized) return;
	Texture* scaled = WindowScaling(tex, size);
	Pixel pixel;
	unsigned int* data = new unsigned int[size.x*size.y];
	for (int i=0; i<size.x; i++) {
		for (int j=0; j<size.y; j++) {
			pixel=scaled->GetPixel(IntVector(i, j));
			data[j*size.x+i]=(((int) (pixel.a*255))<<24)+(((int) (pixel.r*255))<<16)+(((int) (pixel.g*255))<<8)+(((int) (pixel.b*255)));
		}
	}

	SDL_UpdateTexture(screenTexture, NULL, data, size.x * sizeof(unsigned int));
}
void SDLTarget::Flip() {
	if (!initialized) return;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
void SDLTarget::Ready() {
	if (!initialized) return;
	SDL_DestroyTexture(screenTexture);
	screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, size.x, size.y);
}
void SDLTarget::Initialize(IntVector destSize) {
	if (initialized) End();
	size=destSize;
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) throw(1);
	window = SDL_CreateWindow("Generic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_SHOWN);
	if( window == NULL ) throw("3");
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) throw(true);
	screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, size.x, size.y);
	if (screenTexture==NULL) throw(1.2);
	initialized=true;
}

SDLTarget::SDLTarget() : size(IntVector(0,0)){

}

SDLTarget::~SDLTarget() {
	if (initialized) End();
}

void SDLTarget::End() {
	if (!initialized) return;
	SDL_DestroyTexture(screenTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	initialized=false;
}
