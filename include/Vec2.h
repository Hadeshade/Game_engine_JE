//Feito por Marco Antonio Nemetala Garcia
#ifndef VEC2_H
#define VEC2_H

class Vec2
{
private:
    /* data */
public:
    Vec2(float x, float y);
    float x;
    float y;
    Vec2 GetRotated(float pos);
    Vec2 operator+(const Vec2& vec) const;
    Vec2 operator+(const float escalar) const;
    ~Vec2();
    
};



#endif