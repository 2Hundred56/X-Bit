/*
 * PaletteTexture.h
 *
 *  Created on: Sep 6, 2019
 *      Author: triforce
 */

#ifndef PALETTETEXTURE_H_
#define PALETTETEXTURE_H_

#include "Texture.h"
class Palette;
class PaletteTexture: public Texture {
public:
	PaletteTexture(int, int, unsigned short*, Palette*);
	virtual ~PaletteTexture();
	virtual Pixel getPixel(IntVector);
	virtual int getWidth() {
		return width;
	}
	virtual int getHeight() {
		return height;
	}
protected:
	int width, height;
	Palette* palette;
	unsigned short* data;
};

#endif /* PALETTETEXTURE_H_ */
