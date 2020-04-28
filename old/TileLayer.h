/*
 * TileLayer.h
 *
 *  Created on: Mar 11, 2020
 *      Author: triforce
 */

#ifndef TILELAYER_H_
#define TILELAYER_H_

#include "CollisionLayer.h"
#include "RenderLayer.h"
class Tileset;
class Tile;
class TileLayer: public CollisionLayer, public RenderLayer {
public:
	TileLayer(CentralManager* m, unsigned int w, unsigned int h, unsigned int tw, unsigned int th);
	virtual ~TileLayer();
	virtual std::vector<CollisionHandle*> Check(CollisionHandle* handle, Vector sweep);
	virtual Tile* GetTile(int x, int y);
	virtual void Render();
//protected:
	unsigned int* tilesetData;
	unsigned int* tileData;
	unsigned int width, height;
	unsigned int tileWidth, tileHeight;
	std::vector<Tileset*> tilesets;
};

#endif /* TILELAYER_H_ */
