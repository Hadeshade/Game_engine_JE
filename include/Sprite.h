// Feito por Marco Antonio Nemetala Garcia 
// Sprite irá tomar conta de uma imagem dentro do state;

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "Component.h"
#include "GameObject.h"

class Sprite  : public Component
{
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
public:
    Sprite(GameObject& gameObj);
    Sprite(std::string file,GameObject& gameObj);
    ~Sprite();
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    // void Render(int x, int y);
    void Render();
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float dt);
    bool Is(std::string type);

};




#endif