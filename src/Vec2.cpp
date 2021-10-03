//Feito por Marco Antonio Nemetala Garcia
#include "Vec2.h"

// Construtor
Vec2::Vec2(float x, float y): x(x), y(y)
{
}

// Destrutor
Vec2::~Vec2()
{
}

Vec2 Vec2::GetRotated(float pos)
{
    return Vec2(x,y);
}

Vec2 Vec2::operator+(const Vec2& vec) const {

  return Vec2(Vec2::x + vec.x, Vec2::y + vec.y);

}

Vec2 Vec2::operator+(const float escalar) const {

  return Vec2(Vec2::x + escalar, Vec2::y + escalar);

}