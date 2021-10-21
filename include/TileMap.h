// Feito por Marco Antonio Nemetala Garcia

#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>
#include "Component.h"
#include "TileSet.h"

class TileMap : public Component 
{
private:
    std::vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

public:
    TileMap(GameObject& associated, std::string file, TileSet* tileSetado);
    void Load(std::string file);
    void SetTileSet(TileSet* tileSetado);
    int At(int x, int y, int z);
    void Render();
    void RenderLayer(int layer,int cameraX, int cameraY);
    int GetWidth();
    int GetHeight();
    int GetDepth();
    ~TileMap();
};


#endif