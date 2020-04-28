/*
 * RenderTexture.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef RENDERTARGET_H_
#define RENDERTARGET_H_
class IntVector;
class Texture;
class RenderTarget {
	virtual IntVector DestinationSize() = 0;
	virtual void Render(Texture* tex) = 0;
	virtual void Flip() = 0;
	virtual void Ready() = 0;
	virtual void Initialize(IntVector destSize) = 0;
	virtual void End() = 0;
};

#endif /* RENDERTARGET_H_ */
