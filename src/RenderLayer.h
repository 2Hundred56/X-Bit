/*
 * RenderLayer.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef RENDERLAYER_H_
#define RENDERLAYER_H_
class BasicTexture;
class Rect;
class RenderLayer {
public:
	virtual ~RenderLayer() {

	}
	virtual BasicTexture* Render(Rect r) = 0;
};

#endif /* RENDERLAYER_H_ */
