/*
 * BasicTexture.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#include "BasicTexture.h"
#include "IntVector.h"
#include "Pixel.h"
BasicTexture::BasicTexture(IntVector dimensions, Pixel base) {
	this->dimensions=dimensions;
	data = new Pixel[dimensions.x*dimensions.y];
	for (int i = 0; i < dimensions.x*dimensions.y; i++) data[i] = base;
}

BasicTexture::~BasicTexture() {
	delete data;
}

Pixel BasicTexture::getPixel(IntVector location) {
	return data[location.y*dimensions.y+location.x];
}

BasicTexture::BasicTexture(IntVector dimensions) : BasicTexture(dimensions, Pixel(0,0,0,1)){

}

IntVector BasicTexture::getSize() {
	return dimensions;
}

Pixel BasicTexture::setPixel(IntVector location, Pixel px) {
	data[location.y*dimensions.y+location.x]=px;
}
