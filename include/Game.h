// Feito por Marco Antonio Nemetala Garcia;
/*
    Classe Game é responsável por inicializar recursos, rodar o loop principal
do jogo e liberar os recursos quando o jogo for encerrado;
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "State.h"



class Game
{
private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state = nullptr;
    Game(std::string ,int , int  );
public:
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();

};




#endif