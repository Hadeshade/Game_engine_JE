// Feito por Marco Antonio Nemetala Garcia

#include "TileSet.h"

TileSet::TileSet(int tileW, int tileH, std::string file)
{
    tileWidth = tileW;
    tileHeight = tileH;
    // Abre o Sprite, mas com qual GameObject?;
}

void TileSet::RenderTile(unsigned index, float x, float y)
{
    // Não faço ideia do que ele quer aqui!
}

int TileSet::GetTileHeight()
{
    return tileHeight;
}

int TileSet::GetTileWidth()
{
    return tileWidth;
}

TileSet::~TileSet()
{

}