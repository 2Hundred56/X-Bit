/*
 * TestLine.cpp
 *
 *  Created on: Mar 25, 2020
 *      Author: triforce
 */

#include "TestLine.h"
#include "Palette.h"
#include "Pixel.h"
#include "PaletteTexture.h"
#include "CollisionTerms.h"
#include "CentralManager.h"
#include "CollisionManager.h"
#include "TestHandle.h"
void TestLine::Initialize() {
	std::vector<Pixel> pixels = std::vector<Pixel>();
	//pixels.push_back(Pixel(0,0,0,0));
	pixels.push_back(Pixel(1,1,1,1));
	pixels.push_back(Pixel(0,0,0,0));
	Palette* palette = new Palette(pixels);
	unsigned short* data = new unsigned short[(int) (slope.x*2*slope.y*2)];
	for (int i = 0; i<(int) (slope.x*2); i++) {
		int trueY = (int) ((i-slope.x)*slope.y/slope.x+slope.y);
		if (trueY<slope.y*2) {
			data[(int) (trueY*slope.x*2+i)]=1;
		}
	}
	t = new PaletteTexture(slope.x*2, slope.y*2, data, palette);
	h = new TestHandle(position, new AABB(slope.x, slope.y), GROUND, SOLID);
	manager->collision->RegisterHandle(h);
}

TestLine::TestLine(float x, float y) {
	slope = Vector(x, y);
}

void TestLine::Update() {
	std::cout<<"Updated"<<std::flush;
}

void TestLine::Render() {
	manager->RenderTexture(t, position-slope);
}
