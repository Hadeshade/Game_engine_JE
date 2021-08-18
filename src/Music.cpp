// Feito por Marco Antonio Nemetala Garcia
#include "Music.h"


Music::Music()
{
    music = nullptr;
}

Music::Music(std::string file)
{
    Open(file);
}

void Music::Play(int times)
{
    if (music != nullptr)
    {
        Mix_PlayMusic(music, times);
    }
    
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file)
{
    music = Mix_LoadMUS(file.c_str());
    if(!music)
    {
        printf("Mix_LoadMUS: %s\n", Mix_GetError());
        exit(-1);
    }

    // Faz a música rodar...
    Play(1);

}

bool Music::IsOpen()
{
    if(music == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

Music::~Music()
{
    Stop();
    Mix_FreeMusic(music);
}