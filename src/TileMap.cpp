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
    int valor;
    int teste[3];
    int parametro = 0;
    std::string cont;
    std::string dados;
    std::getline(mapeamento, cont);
    std::string dimensao = cont;

    // Separar os dados da dimensão
    for (int i = 0; i < dimensao.size(); i++)
    {
        if(dimensao.at(i) != ','){
            valor = 10 * valor; // Pegar a dezena do número
            valor += dimensao.at(i) - '0';
        }
        else{
            teste[parametro] = valor;
            valor = 0;
            parametro++;
        }
    }
    mapWidth = teste[0];
    mapHeight = teste[1];
    mapDepth = teste[2];

    

    valor = 0;
    while (std::getline(mapeamento, cont))
    {
        // Evita pegar a linha dos parametros
        if (cont == dimensao)
        {
            continue;
        }
        
        // Pega todo o conteúdo e ja coloca dentro do tileMatrix retirando 1;
        for (int i = 0; i < cont.size(); i++) {
            if (cont.at(i) >= '0' && cont.at(i) <= '9') {
                valor = 10 * valor; // Pegar a dezena do número
                valor += cont.at(i) - '0';
            } else if (cont.at(i) == ',') {
            tileMatrix.push_back(valor - 1);
            valor = 0;
            } else {
                valor = 0;
            }
        }
    }
    
    // Fecha o arquivo 
    mapeamento.close();

}

void TileMap::SetTileSet(TileSet* tileSetado)
{
    tileSet = tileSetado;
}

void TileMap::Render()
{
    
}

void TileMap::RenderLayer(int layer,int cameraX, int cameraY)
{
    
}

int TileMap::GetWidth()
{
    return mapWidth;
}

int TileMap::GetHeight()
{
    return mapHeight;
}

int TileMap::GetDepth()
{
    return mapDepth;
}

TileMap::~TileMap()
{
}

