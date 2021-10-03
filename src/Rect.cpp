// Feito por Marco Antonio Nemetala Garcia
#include "Rect.h"

// Contrutor
Rect::Rect(): x(0), y(0), w(0), h(0)
{
}

// Destrutor
Rect::~Rect()
{
}

bool Rect::Contains(float posx, float posy) 
{
    if (posx >= x &&
      posy >= y &&
      posx <= x + w &&
      posy <= y + h) {
    return true;
  }
  return false;
}