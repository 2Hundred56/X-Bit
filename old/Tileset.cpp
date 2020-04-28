/*
 * Tileset.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#include "Tileset.h"
#include "Tile.h"
Tileset::Tileset(std::vector<Tile*> tiles, Palette* p) : tiles(tiles), palette(p) {
}

Tileset::~Tileset() {
	for (auto it = tiles.begin(); it!=tiles.end(); it++) {
		delete (*it);
	}
}

Tile* Tileset::GetTile(int tile) {
	return tiles[tile];
}
