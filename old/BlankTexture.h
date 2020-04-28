/*
 * BlankTexture.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef BLANKTEXTURE_H_
#define BLANKTEXTURE_H_

#include "Texture.h"
class BlankTexture: public Texture {
public:
	BlankTexture(int w, int h);
	virtual ~BlankTexture();
	virtual Pixel getPixel(IntVector);
	virtual int getWidth();
	virtual int getHeight();
protected:
	int w, h;
};

#endif /* BLANKTEXTURE_H_ */
