/*
 * BasicTexture.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef BASICTEXTURE_H_
#define BASICTEXTURE_H_
#include "Texture.h"
class IntVector;
class Pixel;
class BasicTexture: public Texture {
public:
	BasicTexture(IntVector dimensions);
	BasicTexture(IntVector dimensions, Pixel base);
	virtual ~BasicTexture();
	virtual Pixel getPixel(IntVector);
	virtual IntVector getSize();
	virtual Pixel setPixel(IntVector location, Pixel px);
protected:
	IntVector dimensions;
	Pixel* data;
};

#endif /* BASICTEXTURE_H_ */
