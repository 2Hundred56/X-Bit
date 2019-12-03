/*
 * Pixel.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#include "Pixel.h"

Pixel& operator +=(Pixel &p1, Pixel p2) {
	p1 = Pixel(p1.r * (1 - p2.a) + p2.r * p2.a, p1.g * (1 - p2.a) + p2.g * p2.a,
			p1.b * (1 - p2.a) + p2.b * p2.a, 1);
	return p1;
}

bool operator <(const ZPixel &p1, const ZPixel &p2) {
	return p1.second < p2.second;
}

bool operator ==(Pixel p1, Pixel p2) {
	return (p1.r == p2.r) && (p1.g == p2.g) && (p1.b == p2.b) && (p1.a == p2.a);
}

std::ostream& operator <<(std::ostream &char_traits, Pixel pixel) {
	char_traits << "(" << pixel.r << "," << pixel.g << "," << pixel.b << "," << pixel.a << ")";
	return char_traits;
}
