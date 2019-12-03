/*
 * ResourceManager.h
 *
 *  Created on: Nov 26, 2019
 *      Author: triforce
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#include <fstream>
#include <vector>
#include <map>
class PaletteTexture;
class Palette;
class Tileset;
class Shape;
class ResourceManager {
public:
	ResourceManager();
	virtual ~ResourceManager();
	Tileset* LoadTileset(char* path);
	Shape* GetShape(int shapeID);
	void ConvertTileset(char* path, char* out, int tileSize);
protected:
	std::map<std::string, Tileset*> tilesets;
};

#endif /* RESOURCEMANAGER_H_ */
