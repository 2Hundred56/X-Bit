/*
 * BlankTexture.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#include "BlankTexture.h"
#include "Pixel.h"
#include "IntVector.h"
BlankTexture::BlankTexture(int w, int h) : w(w), h(h) {
	// TODO Auto-generated constructor stub

}

BlankTexture::~BlankTexture() {
	// TODO Auto-generated destructor stub
}

Pixel BlankTexture::getPixel(IntVector iv) {
	return Pixel(1,1,1,1);
}

int BlankTexture::getWidth() {
	return w;
}

int BlankTexture::getHeight() {
	return h;
}
