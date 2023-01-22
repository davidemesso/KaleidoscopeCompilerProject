#include <iostream>

extern "C" {
    double simple(double, double);
    double f(double, double, double);
}

int main() {
    int x, y, z;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "z: ";
    std::cin >> z;
    std::cout << "Il valore di f(x,y,z) è " << f(x,y,z) << std::endl;
}
