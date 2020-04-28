/*
 * SDLTarget.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef SDLTARGET_H_
#define SDLTARGET_H_
struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Window;
#include "RenderTarget.h"
#include "IntVector.h"
class SDLTarget: public RenderTarget {
	virtual ~SDLTarget();
	SDLTarget();
	virtual IntVector DestinationSize();
	virtual void Render(Texture* tex);
	virtual void Flip();
	virtual void BeginGraphics();
	virtual void Initialize(IntVector destSize);
	virtual void End();
protected:
	IntVector size;
	SDL_Texture* screenTexture = 0;
	SDL_Renderer* renderer = 0;
	SDL_Window* window = 0;
	bool initialized = false;
};

#endif /* SDLTARGET_H_ */
