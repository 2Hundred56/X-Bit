/*
 * main.cpp
 *
 *  Created on: Mar 11, 2020
 *      Author: triforce
 */

#include <iostream>
#include <vector>
#include <string>
#include "SDL2/SDL.h"
unsigned int getpixel(SDL_Surface *surface, int x, int y)
{

	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16 *)p;
		break;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32 *)p;
		break;

	default:
		return 0;
	}
}
int main(int argc, char* args[]) {
	int i = 0;
	std::vector<unsigned int> palettes;
	std::string s;
	while (true) {
		std::cout<<"Input palette #"<<i<<", or type q to break:"<<std::flush;
		std::cin>>s;
		if (s[0]=='q') break;
		unsigned int f = std::stol(s, nullptr, 16);
		std::cout<<((f&0xFF000000)>>24)<<","<<((f&0x00FF0000)>>16)<<","<<((f&0x0000FF00)>>8)<<","<<((f&0x000000FF))<<"\n";
		palettes.push_back(f);
	}
}

