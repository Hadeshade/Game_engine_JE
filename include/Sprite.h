// Feito por Marco Antonio Nemetala Garcia 
// Sprite irá tomar conta de uma imagem dentro do state;

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Sprite
{
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
public:
    Sprite();
    Sprite(std::string file);
    ~Sprite();
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};




#endif