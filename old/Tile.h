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
	Tile(Shape* s = 0, Texture* t = 0, unsigned char sf = 0, unsigned char tf = 0) : shape(s), texture(t), sortingFlag(sf), typeFlag(tf) {

	}
	unsigned char GetSortingFlag() {
		return sortingFlag;
	}
	unsigned char GetTypeFlag() {
		return typeFlag;
	}
protected:
	unsigned char sortingFlag;
	unsigned char typeFlag;
};



#endif /* TILE_H_ */
