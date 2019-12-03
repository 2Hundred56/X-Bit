/*
 * RenderLayer.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef RENDERLAYER_H_
#define RENDERLAYER_H_

class RenderLayer {
	virtual ~RenderLayer() {

	}
	virtual void Render() = 0;
};



#endif /* RENDERLAYER_H_ */
