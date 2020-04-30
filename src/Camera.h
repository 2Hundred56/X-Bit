/*
 * Camera.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "Rect.h"
#include <vector>
class CentralManager;
class RenderTarget;
class BasicTexture;
class Camera {
public:
	Camera(CentralManager* m, Rect area);
	virtual ~Camera();
	void Ready();
	void Snap();
	void SetTarget(RenderTarget*);
	BasicTexture* CurrentTexture();
	Rect GetCaptureArea();
protected:
	bool hasSnapped = false;
	Rect area;
	CentralManager* manager;
	BasicTexture* texture;
	RenderTarget* renderTarget = 0;
};

#endif /* CAMERA_H_ */
