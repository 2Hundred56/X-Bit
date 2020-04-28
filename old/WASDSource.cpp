/*
 * WASDSource.cpp
 *
 *  Created on: Mar 18, 2020
 *      Author: triforce
 */

#include "WASDSource.h"
#include "SDL2/SDL.h"
void WASDSource::Update() {
	SDL_PumpEvents();
	const unsigned char* kstate = SDL_GetKeyboardState(NULL);
	bool a = kstate[SDL_SCANCODE_SPACE];
	bool b = kstate[SDL_SCANCODE_F];
	bool c = kstate[SDL_SCANCODE_LSHIFT];
	bool d = kstate[SDL_SCANCODE_G];
	bool negX = kstate[SDL_SCANCODE_A];
	bool negY = kstate[SDL_SCANCODE_W];
	bool posX = kstate[SDL_SCANCODE_D];
	bool posY = kstate[SDL_SCANCODE_S];
	if (A==PRESSED || A==ON) A = a?ON:RELEASED;
	else if (A==RELEASED || A==OFF) A = a?PRESSED:OFF;
	if (B==PRESSED || B==ON) B = b?ON:RELEASED;
	else if (B==RELEASED || B==OFF) B = b?PRESSED:OFF;
	if (C==PRESSED || C==ON) C = c?ON:RELEASED;
	else if (C==RELEASED || C==OFF) C = c?PRESSED:OFF;
	if (D==PRESSED || D==ON) D = d?ON:RELEASED;
	else if (D==RELEASED || D==OFF) D = d?PRESSED:OFF;
	//A=PRESSED;
	X=(posX?1:0)-(negX?1:0);
	Y=(posY?1:0)-(negY?1:0);
}
