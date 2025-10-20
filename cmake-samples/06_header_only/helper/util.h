#include <iostream>

class Util
{
public:
    Util() = default;
    static void print(const char* s);
    static void print(int a);
};

void Util::print(const char* s)
{
    std::cout << s;
};

void Util::print(int a)
{
    std::cout << "The integer is " << a << '\n';
};