/*
 * Pixel.hpp
 *
 *  Created on: Sep 4, 2019
 *      Author: triforce
 */

#ifndef PIXEL_H_
#define PIXEL_H_
#include <utility>
#include <iostream>
class Pixel {
public:
	float r;
	float g;
	float b;
	float a;
	Pixel(float r=0, float g=0, float b=0, float a = 1) : r(r), g(g), b(b), a(a){

	}
	Pixel(const Pixel& p) {
		r = p.r;
		g = p.g;
		b = p.b;
		a = p.a;
	}
};
Pixel& operator +=(Pixel &p1, Pixel p2);

bool operator ==(Pixel p1, Pixel p2);

std::ostream& operator<<(std::ostream&, Pixel);
#endif /* PIXEL_H_ */
