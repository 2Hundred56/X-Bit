/*
 * RenderTarget.h
 *
 *  Created on: Sep 4, 2019
 *      Author: triforce
 */

#ifndef RENDERTARGET_H_
#define RENDERTARGET_H_
class IntVector;
class RenderTarget {
public:
	virtual ~RenderTarget() {

	}
	virtual void Render(unsigned int* data, IntVector texture) = 0;
	virtual void Flip() = 0;
	virtual void BeginGraphics() = 0;
	virtual void Initialize(IntVector screen, IntVector texture) = 0;
	virtual void CloseGraphics() = 0;
};

#endif /* RENDERTARGET_H_ */
