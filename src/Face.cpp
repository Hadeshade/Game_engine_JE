// Feito por Marco Antonio Nemetala Garcia
#include "Face.h"

Face::Face(GameObject& associated) : Component(associated), hitpoints(30)
{
}

Face::~Face()
{
}

void Face::Damage(int damage = 30)
{
    hitpoints -= damage;
    if(hitpoints <= 0)
    {
        associated.RequestDelete();
    }
}

void Face::Update(float dt)
{}

void Face::Render()
{}

bool Face::Is(std::string type)
{
    if(type.compare("Face") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}