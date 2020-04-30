/*
 * BasicTexture.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#include "BasicTexture.h"
#include "IntVector.h"
#include "Pixel.h"
#include <cmath>
#include "Timer.h"
BasicTexture::BasicTexture(IntVector size, Pixel base) : dimensions(size) {
	data = new Pixel[dimensions.x*dimensions.y];
	Timer* t = new Timer();
	for (int i = 0; i < dimensions.x*dimensions.y; i++) data[i] = base;
}

BasicTexture::~BasicTexture() {
	delete data;
}

Pixel BasicTexture::GetPixel(IntVector location) {
	return data[location.y*dimensions.y+location.x];
}

BasicTexture::BasicTexture(IntVector dimensions) : BasicTexture(dimensions, Pixel(0,0,0,1)){

}

IntVector BasicTexture::GetSize() {
	return dimensions;
}

void BasicTexture::SetPixel(IntVector location, Pixel px) {
	data[location.y*dimensions.y+location.x]=px;
}

void BasicTexture::Blit(Texture *tex, IntVector origin) {
	float iMax = std::min(tex->GetSize().x, dimensions.x-origin.x);
	float jMax = std::min(tex->GetSize().y, dimensions.y-origin.y);
	for (int i=0; i<iMax; i++) {
		for (int j=0; j<jMax; j++) {
			data[(j+origin.y)*dimensions.y+(i+origin.x)]+=tex->GetPixel(IntVector(i, j));
		}
	}
}
