/*
 * GraphicsWrapper.h
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#ifndef GRAPHICSMANAGER_H_
#define GRAPHICSMANAGER_H_
#include <vector>
#include "Pixel.h"
class Vector;
class RenderData;
class Texture;
class RenderTarget;
class IntVector;
class GraphicsManager {
public:
	GraphicsManager();
	virtual ~GraphicsManager();
	void RenderTexture(Texture*, IntVector, RenderData, float z = 0);
	void RenderTexture(Texture*, IntVector, float z = 0);
	unsigned int* Process();
	bool InBounds(IntVector);
	void AddPixel(IntVector, Pixel);
	void Prepare(IntVector dimen);
private:
	std::vector<Pixel>** data;
	int width, height;
};

#endif /* GRAPHICSMANAGER_H_ */
