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
    int dimMapa[3];
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
            dimMapa[parametro] = valor;
            valor = 0;
            parametro++;
        }
    }
    mapWidth = dimMapa[0];
    mapHeight = dimMapa[1];
    mapDepth = dimMapa[2];

    

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

int TileMap::At(int x, int y, int z)
{
    // Retornar o valor do vetor que corresponde a Matriz;
    // Assumindo que começa com 0 exemplo: x=0 , y=0 e z= 0;
    int dim = z * mapHeight * mapWidth;
    int altura = y * mapWidth;
    return (x + altura + dim);

}

void TileMap::Render()
{
    // Precisa do RenderLayer que eu não sei como fazer!
}

void TileMap::RenderLayer(int layer,int cameraX = 0, int cameraY = 0)
{
    for (int j = 0; j < mapHeight; j++)
    {
        for (int i = 0; i < mapWidth; i++)
        {
            tileSet->RenderTile(At(i,j,layer), i*tileSet->GetTileWidth() - cameraX, j*tileSet->GetTileHeight() - cameraY );
        }
    }
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

void TileMap::Update(float dt = 0)
{

}

bool TileMap::Is(std::string type)
{
    if (type == "TileMap")
    {
       return true; 
    }
    return false;
}

TileMap::~TileMap()
{
    tileSet = nullptr;
    tileMatrix.clear();
}


