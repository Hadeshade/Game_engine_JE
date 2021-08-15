// Feito por Marco Antonio Nemetala Garcia

#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Sprite.h"
#include "Music.h"

class State
{
private:
    Sprite bg;
    Music music;
    bool quitRequested;
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
    ~State();
};


#endif