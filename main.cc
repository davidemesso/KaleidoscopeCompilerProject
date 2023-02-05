#include <iostream>
#include <cstdio>

extern "C" 
{
    double f(double x);
}

int main()
{
    f(5);
    f(50);
}
