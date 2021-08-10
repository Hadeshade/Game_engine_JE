// Feito por Marco Antonio Nemetala Garcia 

#include <iostream>
#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    // State* state;
public:
    Game(std::string ,int , int  );
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    //State& GetState();
    static Game& GetInstance();

};

// Game::Game(std::string title, int width, int height)
// {
// }

// Game::~Game()
// {
// }




#endif