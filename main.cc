#include <iostream>
#include <cstdio>

extern "C" {
    double simple(double, double);
    double f(double, double, double);
    double pr(double);
    double allMultiplesUntil(double, double);
}

int main() {
    for(int i = 0; i < 20; i+=3)
        std::cout << i << std::endl;   
}
