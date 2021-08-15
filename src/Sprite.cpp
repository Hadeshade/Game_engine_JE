// Feito por Marco Antonio Nemetala Garcia 

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite()
{
    texture = nullptr;
}

Sprite::Sprite(std::string file)
{
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file)
{
    // Verifica se tem alguma imagem carregada antes;
    if(texture != nullptr)
    {
        texture = nullptr;
    }

    // Carregando a textura e trantadando erro:
    texture = IMG_LoadTexture( Game::GetInstance().GetRenderer(), file.c_str());
    if(texture == nullptr)
    {
        printf("IMG_LoadTexture: %s\n", IMG_GetError());
    }

    width = 1024;
    height = 600;

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

// Uma wrapper para a função SDL_RenderCopy;
void Sprite::Render(int x, int y)
{
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
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
