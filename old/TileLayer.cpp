/*
 * TileLayer.cpp
 *
 *  Created on: Mar 11, 2020
 *      Author: triforce
 */

#include "TileLayer.h"
#include "Tileset.h"
#include "Tile.h"
#include "CentralManager.h"
#include "CollisionTerms.h"
TileLayer::~TileLayer() {
	// TODO Auto-generated destructor stub
}

TileLayer::TileLayer(CentralManager *m, unsigned int w, unsigned int h,
		unsigned int tw, unsigned int th) : RenderLayer(m), width(w), height(h), tileWidth(tw), tileHeight(th) {
	tilesets.push_back(0);
	tilesetData = new unsigned int[w*h];
	tileData = new unsigned int[w*h];
}

Tile* TileLayer::GetTile(int x, int y) {
	if (x<0 || x>width || y<0 || y>height) return 0;
	if (tilesetData[y*width+x]==0) return 0;
	return tilesets[tilesetData[y*width+x]]->GetTile(tileData[y*width+x]);
}

std::vector<CollisionHandle*> TileLayer::Check(CollisionHandle *handle,
		Vector sweep) {
	Rect r = handle->GetShape()->ContainBox();
	int minX = (int) ((handle->GetPos().x-r.w/2.0)/tileWidth)-1;
	int maxX = (int) ((handle->GetPos().x+r.w/2.0+sweep.x)/tileWidth)+1;
	int minY = (int) ((handle->GetPos().y-r.h/2.0)/tileHeight)-1;
	int maxY = (int) ((handle->GetPos().y+r.h/2.0+sweep.y)/tileHeight)+1;
	std::vector<CollisionHandle*> handles = std::vector<CollisionHandle*>();
	for (int i = minX; i<=maxX; i++) {
		for (int j = minY; j<=maxY; j++) {
			Tile* t = GetTile(i, j);
			if (t==0) continue;
			if (t->shape==0) continue;
			handles.push_back(new TileHandle(t, Vector(((float) i+1/2)*tileWidth, ((float) j+1/2)*tileHeight)));
		}
	}
	return handles;
}

void TileLayer::Render() {
	int minX=(int) (manager->GetCamera().x/tileWidth) - 1;
	int maxX=(int) ((manager->GetCamera().x+manager->GetCamera().w)/tileWidth) + 1;
	int minY = (int) (manager->GetCamera().y/tileHeight) - 1;
	int maxY=(int) ((manager->GetCamera().y+manager->GetCamera().h)/tileHeight) + 1;

	for (int i = minX; i<maxX; i++) {
		for (int j = minY; j<maxY; j++) {

			Tile* t = GetTile(i, j);
			if (t==0) continue;
			manager->RenderTexture(t->texture, Vector(i*tileWidth+manager->GetCamera().x, j*tileHeight+manager->GetCamera().y));
		}
	}

	//throw 3;
}
