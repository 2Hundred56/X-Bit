/*
 * RenderTarget.cpp
 *
 *  Created on: Apr 29, 2020
 *      Author: triforce
 */

#include "TextureScaling.h"
#include "Texture.h"
#include "BasicTexture.h"
#include "IntVector.h"
#include "Rect.h"
#include <algorithm>
#include <cmath>
#include "Pixel.h"
#include "Constants.h"
#include "Timer.h"
Texture* WindowScaling(Texture *base, IntVector targetSize) {
	float multiplier = std::min(((float) targetSize.x)/((float) base->GetSize().x),((float) targetSize.x)/((float) base->GetSize().x));
	if (PERFECTSCALING) multiplier = (int) multiplier;
	Texture* scaledTexture = Scale(base, base->GetSize()*multiplier);
	BasicTexture* dest = new BasicTexture(targetSize);
	dest->Blit(scaledTexture, IntVector(targetSize.x/2-scaledTexture->GetSize().x/2, targetSize.x/2-scaledTexture->GetSize().x/2));
	return dest;
}

Texture* Scale(Texture *base, IntVector targetSize) {
	float xscale = targetSize.x/base->GetSize().x;
	float yscale = targetSize.y/base->GetSize().y;
	float bx = base->GetSize().x;
	float by = base->GetSize().y;
	BasicTexture* output = new BasicTexture(targetSize);
	Timer* t = new Timer();
	std::cout<<targetSize<<"\n"<<std::flush;
	t->Mark();
	for (int i = 0; i < targetSize.x; i++) {
		for (int j = 0; j < targetSize.y; j++) {
			output->SetPixel(IntVector(i, j), base->GetPixel(IntVector(i/ xscale, j / yscale)));
		}
	}
	std::cout<<1.0/t->Mark()<<"\n"<<std::flush;
	return output;
}
