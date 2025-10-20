#include "arithmetic.h"

int Arithmetic::add(const int a, const int b)
{
    return a + b;
}

int Arithmetic::multiply(const int a, const int b)
{
    return a * b;
}


Rect::Rect() : 
_base{0, 0},
_length{0},
_height{0}
{

}

Rect::Rect(std::pair<int, int> base, int l, int h) :
_base{base},
_length{l},
_height{h}
{

}

int Rect::surface()
{
    return _length * _height;
}

int Rect::periphery()
{
    return (_length + _height) * 2;
}

void Rect::setLength(int l)
{
    _length = l;
}

void Rect::setHeight(int h)
{
    _height = h;
}
