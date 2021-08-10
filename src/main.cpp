#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char** argv){
    Game game = Game::GetInstance();

    SDL_Delay(5000);

    return 0;
}