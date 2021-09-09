// Feito por Marco Antonio Nemetala Garcia
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <algorithm>
#include <string>
#include <SDL2/SDL.h>
#include "Component.h"

class GameObject
{
private:
    std::vector<Component*> components;
    bool isDead;
public:
    GameObject();
    ~GameObject();
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);
    SDL_Rect box;
};


#endif