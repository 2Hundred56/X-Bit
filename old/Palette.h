/*
 * Palette.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef PALETTE_H_
#define PALETTE_H_
#include <vector>
#include "Pixel.h"
class Palette {
public:
	Palette(std::vector<Pixel> p) : pixels(p) {

	}
	Pixel getPixel(char n) {
		return pixels[n];
	}
	std::vector<Pixel> pixels;
};



#endif /* PALETTE_H_ */
