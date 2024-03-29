// Feito por Marco Antonio Nemetala Garcia 

#include "Sprite.h"
#include "Game.h"
#include "Resources.h"


//Construtor
Sprite::Sprite(GameObject& gameObj) : Component(gameObj)
{
    texture = nullptr;
}

// Sobrecarga de Construtor
Sprite::Sprite(std::string file,GameObject& gameObj) : Component(gameObj)
{
    texture = nullptr;
    Open(file);
}

// Destrutor
Sprite::~Sprite()
{
    // SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file)
{
    // // Verifica se tem alguma imagem carregada antes;
    // if(texture != nullptr)
    // {
    //     texture = nullptr;
    // }

    // Carregando a textura e trantadando erro:
    // texture = IMG_LoadTexture( Game::GetInstance().GetRenderer(), file.c_str());
    texture = Resources::GetImage(file);

    // Não precisa mais do código abaixo pois faz isso em Resources;
    // if(texture == nullptr)
    // {
    //     printf("IMG_LoadTexture: %s\n", IMG_GetError());
    // }

    // width = 1024;
    // height = 600;

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0,0,width,height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}


// Uma wrapper para a função SDL_RenderCopy;
void Sprite::Render() // (int x, int y)
{
    SDL_Rect dstRect;
    dstRect.x = associated.box.x ; // GameObject::box.x;
    dstRect.y = associated.box.y ; // GameObject::box.y;
    dstRect.w = clipRect.w;
    dstRect.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(),texture, &clipRect, &dstRect);

}

// Uma wrapper para a função SDL_RenderCopy;
void Sprite::Render(int x, int y) // (int x, int y)
{
    SDL_Rect dstRect;
    dstRect.x = x ; // GameObject::box.x;
    dstRect.y = y ; // GameObject::box.y;
    dstRect.w = clipRect.w;
    dstRect.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(),texture, &clipRect, &dstRect);

}

// Retorna a largura da imagem
int Sprite::GetWidth()
{
    return width;
}

// Retorna a altura da imagem
int Sprite::GetHeight()
{
    return height;
}

// Retorna true se texture estiver alocada
bool Sprite::IsOpen()
{
    if (texture == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Função herdada de Component
void Sprite::Update(float dt)
{

}

// Função herdada de Component
bool Sprite::Is(std::string type)
{
    if(type == "Sprite")
    {
        return true;
    }
    return false;
}