/*
 * RenderLayer.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef RENDERLAYER_H_
#define RENDERLAYER_H_
class CentralManager;
class RenderLayer {
public:
	RenderLayer(CentralManager* m) : manager(m) {

	}
	virtual ~RenderLayer() {

	}
	virtual void Render() = 0;
protected:
	CentralManager* manager;
};



#endif /* RENDERLAYER_H_ */
