#include <iostream>
#include <cstdio>

extern "C" 
{
    double func(double x, double y);
}

int main()
{
    func(1, 10);
    return 0;
}
