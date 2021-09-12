// Feito por Marco Antonio Nemetala Garcia
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "GameObject.h"

class Component
{
protected:
    GameObject& associated;
public:
    Component(GameObject& associated): associated(associated) {}
    virtual ~Component();
    void virtual Update(float dt) = 0;
    void virtual Render() = 0;
    bool virtual Is(std::string type) = 0;
};



#endif