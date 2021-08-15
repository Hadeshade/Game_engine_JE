// Feito por Marco Antonio Nemetala Garcia

#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Music
{
private:
   Mix_Music* music; 
public:
    Music();
    Music(std::string file);
    void Play(int times=-1);
    void Stop(int msToStop =1500);
    void Open(std::string file);
    bool IsOpen();
    ~Music();
};

#endif