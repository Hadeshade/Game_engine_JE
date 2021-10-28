// Feito por Marco Antonio Nemetala Garcia
#include "Resources.h"
#include "Game.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file){
    //Checa se tem a imagem:
    if(!imageTable.count(file)){
        SDL_Texture* textura = IMG_LoadTexture(Game::GetInstance().GetRenderer(),file.c_str());
        imageTable.emplace(file, textura);
    }
    if (!imageTable.at(file))
    {
        printf("Não é possível carregar a textura: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return imageTable.at(file);
    
}

void Resources::ClearImages(){
    // a função erase não serve;
    imageTable.clear();
}

 
Mix_Music* Resources::GetMusic(std::string file){
    //Checa se tem a musica:
    if(!musicTable.count(file)){
        Mix_Music* musica = Mix_LoadMUS(file.c_str());
        musicTable.emplace(file, musica);
    }
    if (!musicTable.at(file))
    {
        printf("Não é possível carregar a musica: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return musicTable.at(file);
}

void Resources::ClearMusics(){
    // a função erase não serve;
    musicTable.clear();
}


Mix_Chunk* Resources::GetSound(std::string file){
    //Checa se tem a melodia:
    if(!soundTable.count(file)){
        Mix_Chunk* melodia = Mix_LoadWAV(file.c_str());
        soundTable.emplace(file, melodia);
    }
    if (!soundTable.at(file))
    {
        printf("Não é possível carregar a melodia: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return soundTable.at(file);
    
}

void Resources::ClearSounds(){
    // a função erase não serve;
    soundTable.clear();
}
