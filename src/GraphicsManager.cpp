/*
 * GraphicsWrapper.cpp
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#include "GraphicsManager.h"
#include "Texture.h"
#include "Vector.h"
#include "Pixel.h"
#include "IntVector.h"
#include "RenderData.h"
#include <algorithm>
#include <iostream>
GraphicsManager::GraphicsManager() {

}

void GraphicsManager::RenderTexture(Texture* texture, IntVector vector,
		RenderData renderData, float z) {
	//TODO: Process data to align with RenderData
	Vector finalLocation;
	Pixel pixel;
	for (int i=0; i<texture->getWidth(); i++) {
		for (int j=0; j<texture->getHeight(); j++) {
			pixel=texture->getPixel(IntVector(i, j));
			finalLocation=Vector(i, j);
			AddPixel(IntVector(finalLocation)+vector, pixel, z);
		}
	}
}

void GraphicsManager::RenderTexture(Texture* texture, IntVector vector, float z) {
	RenderTexture(texture, vector, RenderData(), z);
}

bool GraphicsManager::InBounds(IntVector vector) {
	return vector.x>=0 && vector.x<width && vector.y>=0 && vector.y<height;
}

unsigned int* GraphicsManager::Process() {
	unsigned int* processed = new unsigned int[width*height];
	Pixel pixel;
	Pixel p;
	std::vector<ZPixel> pixels;
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			pixel=Pixel(0,0,0,1);
			pixels=data[i][j];
			//TODO: Stare at this for 10 minutes
			std::sort(pixels.begin(), pixels.end());
			for (auto it=pixels.begin(); it!=pixels.end(); it++) {
				pixel+=(*it).first;
			}
			processed[j*width+i]=(((int) (pixel.a*255))<<24)+(((int) (pixel.r*255))<<16)+(((int) (pixel.g*255))<<8)+(((int) (pixel.b*255)));

		}
	}
	return processed;
}

GraphicsManager::~GraphicsManager() {
	for (int i=0; i<width; i++) {
		delete data[width];
	}
	delete data;
}

void GraphicsManager::AddPixel(IntVector intVector, Pixel pixel, float z) {
	if (InBounds(intVector)) {
		data[intVector.x][intVector.y].push_back(ZPixel(pixel, z));
	}
}

void GraphicsManager::Prepare(IntVector dimen) {
	width=dimen.x;
	height=dimen.y;
	data = new std::vector<ZPixel>*[width];
	for (int i=0; i<width; i++) {
		data[i]=new std::vector<ZPixel>[height];
	}
}
