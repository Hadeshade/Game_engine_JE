// Feito por Marco Antonio Nemetala Garcia
#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rect
{
private:
    /* data */
public:
    Rect();
    ~Rect();
    float x;
    float y;
    float w;
    float h;

    bool Contains(float posx, float posy);

};




#endif