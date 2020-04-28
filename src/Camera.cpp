/*
 * Camera.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */
#include <vector>
#include "Camera.h"
#include "BasicTexture.h"
#include "IntVector.h"
#include "RenderLayer.h"
#include "CentralManager.h"
Camera::Camera(CentralManager* m, Rect a) {
	manager = m;
	area = a;
	texture = new BasicTexture(IntVector(a.w*manager->PixelsPerUnit(), a.h*manager->PixelsPerUnit()));
}

void Camera::Ready() {
	hasSnapped = false;
	texture = new BasicTexture(IntVector(area.w*manager->PixelsPerUnit(), area.h*manager->PixelsPerUnit()));
}
void Camera::Snap() {
	if (hasSnapped) return;
	std::vector<RenderLayer*> layers = manager->RenderLayers();
	for (auto it = layers.begin(); it!=layers.end(); it++) {
		texture->Blit((*it)->Render(area), IntVector(0, 0));
	}
	hasSnapped = true;
}
BasicTexture* Camera::CurrentTexture() {
	return texture;
}
Rect Camera::GetCaptureArea() {
	return area;
}
