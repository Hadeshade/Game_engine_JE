// Feito por Marco Antonio Nemetala Garcia

#include "Sound.h"

Sound::Sound(GameObject& associated) : Component(associated)
{
    chunck = nullptr;
}

Sound::Sound(GameObject& associated, std::string file) : Sound(associated) // Pode fazer isso?
{
    // Sound(*associated); // Isso tá certo?
    Open(file);
}


void Sound::Play(int times = 1)
{
    channel = Mix_PlayChannel(-1, chunck, times);
}

void Sound::Stop()
{
    if (chunck != nullptr)
    {
        Mix_HaltChannel(channel);
    }  
}

void Sound::Open(std::string file)
{
    chunck = Mix_LoadWAV(file.c_str());
    if(!chunck)
    {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }
}

bool Sound::IsOpen()
{
    return true;
}

void Sound::Update(float dt = 0)
{}

void Sound::Render()
{}

bool Sound::Is(std::string type)
{
    if (type == "Sound")
    {
        return true;
    }
    return false;
    
}
