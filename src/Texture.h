/*
 * Texture.h
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
class Pixel;
class IntVector;
class Texture {
public:
	virtual ~Texture() {

	}
	virtual Pixel GetPixel(IntVector) = 0;
	virtual IntVector GetSize() = 0;
};

#endif /* TEXTURE_H_ */
