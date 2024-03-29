// Feito por Marco Antonio Nemetala Garcia
#ifndef SOUND_H
#define SOUND_H

#include "Component.h"
#include <SDL2/SDL_mixer.h>

class Sound : public Component
{
private:
    Mix_Chunk* chunck;
    int channel;
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, std::string file);

    void Play(int times);
    void Stop();
    void Open(std::string file);
    bool IsOpen();

    void Update(float dt);
    void Render();
    bool Is(std::string type);
};





#endif