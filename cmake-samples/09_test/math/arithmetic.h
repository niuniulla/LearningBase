#include <iostream>

class Rect
{
public:
    Rect();
    Rect(std::pair<int, int>, int, int);
    int surface();
    int periphery();
    void setLength(int l);
    void setHeight(int h);
    inline int getLength() {return _length;};
    inline int getHeight() {return _height;};
    inline std::pair<int, int> getBase() { return _base; };

private:
    std::pair<int, int> _base;
    int _length;
    int _height;
};

class Arithmetic
{
public:
    Arithmetic() = default;
    static int add(const int a, const int b);
    static int multiply(const int a, const int b);
};

