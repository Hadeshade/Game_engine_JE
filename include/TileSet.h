// Feito por Marco Antonio Nemetala Garcia

#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"
#include <string>

class TileSet
{
private:
    // Sprite tileSet;
    int rows;
    int collumns;
    int tileWidth;
    int tileHeight;

public:
    TileSet(int tileWidth, int tileHeight, std::string file);
    void RenderTile (unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
    ~TileSet();
};


#endif