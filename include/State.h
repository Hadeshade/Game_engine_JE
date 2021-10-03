// Feito por Marco Antonio Nemetala Garcia
/*
    State é um "estado da tela de jogo". Podemos ter uma tela de
apresentação, uma tela de NewGame, a tela do jogo em si, uma tela de
fim de jogo, etc. Cada um desses seria um State.
*/

#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <memory>
#include "Sprite.h"
#include "Music.h"

class State
{
private:
    // Sprite bg;
    // Music music;
    bool quitRequested;

    void Input();
    void AddObject(int mouseX, int mouseY);
    std::vector<std::unique_ptr<GameObject>> objectArray;
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    ~State();
};


#endif