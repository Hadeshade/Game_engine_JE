// Feito por Marco Antonio Nemetala Garcia
#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char** argv){
    Game game = Game::GetInstance();
    game.Run();
    
    return 0;
}