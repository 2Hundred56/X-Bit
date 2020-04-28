/*
 * ResourceManager.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#include "ResourceManager.h"
#include <string>
#include "Tileset.h"
#include "PaletteTexture.h"
#include "Pixel.h"
#include "Palette.h"
#include "Tile.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "CollisionTerms.h"
#include <type_traits>
#include "Vector.h"
#include "generated/tileset_generated.h"
unsigned int getpixel(SDL_Surface *surface, int x, int y)
{

	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16 *)p;
		break;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32 *)p;
		break;

	default:
		return 0;
	}
}

ResourceManager::ResourceManager() {
	// TODO Auto-generated constructor stub

}

ResourceManager::~ResourceManager() {

	// TODO Auto-generated destructor stub
}

Tileset* ResourceManager::LoadTileset(char* path) {
	auto it=tilesets.find(std::string(path));
	if (it!=tilesets.end()) return it->second;
	std::ifstream file (path, std::ios::in | std::ios::binary);
	file.seekg (0, file.end);
	int size = file.tellg();
	file.seekg (0, file.beg);
	char* buffer = new char[size];
	file.read(buffer, size);
	auto tileset = resources::GetTileset(buffer);
	auto _tiles = tileset->tiles();
	auto _palette = tileset->palettes();

	Palette* palette = new Palette(std::vector<Pixel>());
	for (int i=0; i<_palette->Length(); i++) {
		auto pix = _palette->Get(i);
		palette->pixels.push_back(Pixel(pix->r(), pix->g(), pix->b(), pix->a()));
	}

	std::vector<Tile*> tiles=std::vector<Tile*>();
	for (int i=0; i<_tiles->Length(); i++) {
		auto til = _tiles->Get(i);
		int w = til->width();
		int h = til->height();
		int id = til->id();
		auto dat = til->data();
		unsigned short* data = (unsigned short*) dat->data();
		tiles.push_back(GetTile(id, w, h, new PaletteTexture(w, h, data, palette)));
	}
	Tileset* set = new Tileset(tiles, palette);
	tilesets.insert(std::pair<std::string, Tileset*>(path, set));
	return set;
}

Tile* ResourceManager::GetTile(int tileID, int w, int h, Texture* t) {
	Shape* s = 0;
	switch (tileID) {
	case 16: s=new AABB(w/2, h/2);
	}
	unsigned char sf;
	unsigned char tf;
	switch (tileID) {
	case 16:
		sf = GROUND;
		tf = SOLID;
	}
	return new Tile(s, t, sf, tf);
}

void ResourceManager::ConvertTileset(char* path, char* out, int tileSize) {

	SDL_Surface* surf = SDL_LoadBMP(path);
	SDL_LockSurface(surf);
	unsigned short* d;
	std::vector<Pixel> pixels = std::vector<Pixel>();
	std::vector<unsigned short*> frames = std::vector<unsigned short*>();
	std::vector<int> frameIDs = std::vector<int>();
	int a;
	for (int i=0; i<(surf->w/tileSize); i++) {
		for (int j=0; j<(surf->h/tileSize); j++) {
			std::cout<<"Making tile "<<Vector(i, j)<<". ID: "<<std::flush;
			std::cin>>a;
			frameIDs.push_back(a);
			d=new unsigned short[tileSize*tileSize];
			for (int i2=0; i2<tileSize; i2++) {
				for (int j2=0; j2<tileSize; j2++) {
					unsigned int color = getpixel(surf, i*tileSize+i2, j*tileSize+j2);
					Pixel p  = Pixel(((color >> 16) & 0xFF)/255.0, ((color >> 8) & 0xFF)/255.0, ((color) & 0xFF)/255.0, ((color >> 24) & 0xFF)/255.0);
					for (unsigned short q=0; q<pixels.size()+1; q++) {
						if (q==pixels.size()) {
							pixels.push_back(p);
							d[j2*tileSize+i2]=q;
							break;
						}
						else {
							if (pixels[q]==p) {
								d[j2*tileSize+i2]=q;
								break;
							}
						}
					}
				}
			}
			frames.push_back(d);
		}
	}
	flatbuffers::FlatBufferBuilder builder(1024);
	resources::Pixel _pixels[pixels.size()];
	for (int i = 0; i<pixels.size(); i++) {
		_pixels[i] = resources::Pixel(pixels[i].r, pixels[i].g, pixels[i].b, pixels[i].a);
	}
	auto _palette = builder.CreateVectorOfStructs(_pixels, pixels.size());
	std::vector<flatbuffers::Offset<resources::Tile> > _tiles = std::vector<flatbuffers::Offset<resources::Tile> >();
	for (int i = 0; i<frameIDs.size(); i++) {
		_tiles.push_back(resources::CreateTile(builder, builder.CreateVector(frames[i], tileSize*tileSize), tileSize, tileSize, frameIDs[i]));
	}
	auto _tiles2 = builder.CreateVector(_tiles);
	auto tileset = resources::CreateTileset(builder, _tiles2, _palette);
	builder.Finish(tileset);
	unsigned char *buf = builder.GetBufferPointer();
	int size = builder.GetSize();
	std::ofstream file (out, std::ios::out | std::ios::binary);
	file.write((char*) buf, size);
	file.close();
}
