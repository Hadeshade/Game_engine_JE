// Feito por Marco Antonio Nemetala Garcia

#include "TileSet.h"

TileSet::TileSet(std::string file, GameObject& associated,int tileW, int tileH) : tileSet(file, associated)
{
    tileWidth = tileW;
    tileHeight = tileH;

    collumns = tileSet.GetWidth()/tileWidth;
    rows = tileSet.GetHeight()/tileHeight;
}

void TileSet::RenderTile(unsigned index, float x, float y)
{
    if(index > -1 && index < rows* collumns){
        tileSet.SetClip(tileWidth * (index % collumns), tileHeight * (index/collumns), tileWidth, tileHeight);
        tileSet.Render(x,y);
    }
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