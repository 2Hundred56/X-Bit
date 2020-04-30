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
#include "RenderTarget.h"
#include "CentralManager.h"
#include "Pixel.h"
Camera::Camera(CentralManager* m, Rect a) {
	manager = m;
	area = a;
	texture = new BasicTexture(IntVector(a.w*manager->PixelsPerUnit(), a.h*manager->PixelsPerUnit()));
}

void Camera::Ready() {
	hasSnapped = false;
	texture = new BasicTexture(IntVector(area.w*manager->PixelsPerUnit(), area.h*manager->PixelsPerUnit()), Pixel(0,0,0,1));
	renderTarget->Ready();
}
void Camera::Snap() {

	if (hasSnapped) return;
	std::vector<RenderLayer*> layers = manager->RenderLayers();
	for (auto it = layers.begin(); it!=layers.end(); it++) {
		texture->Blit((*it)->Render(area), IntVector(0, 0));
	}
	hasSnapped = true;
	renderTarget->Render(texture);
	renderTarget->Flip();
}
BasicTexture* Camera::CurrentTexture() {
	return texture;
}

Camera::~Camera() {
	renderTarget->End();
}

void Camera::SetTarget(RenderTarget* rt) {
	renderTarget = rt;
}

Rect Camera::GetCaptureArea() {
	return area;
}
