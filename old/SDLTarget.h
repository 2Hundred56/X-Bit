/*
 * SDLTarget.h
 *
 *  Created on: Sep 6, 2019
 *      Author: triforce
 */

#ifndef SDLTARGET_H_
#define SDLTARGET_H_

#include "RenderTarget.h"
struct SDL_Texture;
struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Window;
class SDLTarget: public RenderTarget {
public:
	SDLTarget();
	virtual ~SDLTarget();
	virtual void Render(unsigned int* data, IntVector texture);
	virtual void Flip();
	virtual void BeginGraphics();
	virtual void Initialize(IntVector screen, IntVector texture);
	virtual void CloseGraphics();
protected:
	SDL_Texture* screenTexture;
	SDL_Renderer* renderer;
	SDL_Window* window;
	int width, height;
	int screenWidth, screenHeight;
};

#endif /* SDLTARGET_H_ */
