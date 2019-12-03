/*
 * Tile.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef TILE_H_
#define TILE_H_
class Shape;
class Texture;
class Tile {
public:
	Shape* shape;
	Texture* texture;
	Tile(Shape* s = 0, Texture* t = 0) : shape(s), texture(t) {

	}
};



#endif /* TILE_H_ */
