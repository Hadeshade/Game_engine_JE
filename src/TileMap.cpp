// Feito por Marco Antonio Nemetala Garcia

#include "TileMap.h"

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSetado) : Component(associated)
{
    Load(file);
    tileSet = tileSetado;
}

void TileMap::Load(std::string file)
{

}

void TileMap::SetTileSet(TileSet* tileSet)
{
    
}

void TileMap::Render()
{
    
}

void TileMap::RenderLayer(int layer,int cameraX, int cameraY)
{
    
}

TileMap::~TileMap()
{
}

