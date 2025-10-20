#include <iostream>

class Arithmetic
{
public:
    Arithmetic() = default;
    static int add(const int a, const int b);
    static int multiply(const int a, const int b);
};

int Arithmetic::add(const int a, const int b)
{
    return a + b;
};

int Arithmetic::multiply(const int a, const int b)
{
    return a * b;
};