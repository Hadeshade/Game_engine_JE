// Feito por Marco Antonio Nemetala Garcia

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

#include "TileMap.h"

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSetado) : Component(associated)
{
    Load(file);
    tileSet = tileSetado;
}

void TileMap::Load(std::string file)
{
    // Abre o arquivo e verifica se foi aberto corretamente;
    std::ifstream mapeamento(file.c_str());
    if (!mapeamento)
    {
        std::cerr << "Não foi possível abrir o tileMap.txt" << std::endl;
        std::exit(1);
    }

    // Pegando as informações do arquivo;
    std::string cont;
    std::string dados;
    std::getline(mapeamento, cont);
    std::string dimensao = cont;
    while (std::getline(mapeamento, cont))
    {
        if (cont == dimensao)
        {
            continue;
        }
        dados += cont;
        dados.push_back('\n');
    }
    
     
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

