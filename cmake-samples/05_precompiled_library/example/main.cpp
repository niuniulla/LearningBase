#include "util.h"
#include "arithmetic.h"

int main()
{
    Util::print("This is the subdirectory file system example.\n");

    int res = Arithmetic::add(2, 3);
    Util::print(res); 

    res = Arithmetic::multiply(2, 3);
    Util::print(res); 

    return 0;
}