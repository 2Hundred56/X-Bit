/*
 * BasicTexture.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef BASICTEXTURE_H_
#define BASICTEXTURE_H_
#include "Texture.h"
#include "IntVector.h"
class Pixel;
class BasicTexture: public Texture {
public:
	BasicTexture(IntVector dimensions);
	BasicTexture(IntVector dimensions, Pixel base);
	virtual ~BasicTexture();
	virtual Pixel GetPixel(IntVector);
	virtual IntVector GetSize();
	virtual void SetPixel(IntVector location, Pixel px);
	virtual void Blit(Texture* tex, IntVector origin);
protected:
	IntVector dimensions;
	Pixel* data;
};

#endif /* BASICTEXTURE_H_ */
