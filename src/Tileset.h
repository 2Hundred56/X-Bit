/*
 * Tileset.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef TILESET_H_
#define TILESET_H_
#include <vector>
class Tile;
class Palette;
class Tileset {
public:
	Tileset(std::vector<Tile*> tiles, Palette* palette);
	virtual ~Tileset();
	Tile* GetTile(int tile);
protected:
	std::vector<Tile*> tiles;
	Palette* palette;
};

#endif /* TILESET_H_ */
