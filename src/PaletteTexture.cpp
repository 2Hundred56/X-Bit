/*
 * PaletteTexture.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: triforce
 */

#include "PaletteTexture.h"
#include "IntVector.h"
#include "Pixel.h"
#include "Palette.h"

PaletteTexture::PaletteTexture(int w, int h, unsigned short* d,
		Palette* p) : width(w), height(h), data(d), palette(p) {
}

Pixel PaletteTexture::getPixel(IntVector intVector) {
	return palette->getPixel(data[intVector.x*width+intVector.y]);
}

PaletteTexture::~PaletteTexture() {
}
