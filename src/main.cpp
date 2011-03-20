#include <iostream>

#include "light.hpp"

int main(void) {
    Color c1(10,20,30);
    Color c2(40, 50, 60);
    Color c3 = 3*c2;

    std::cout<<c3.red;
    return 0;
}
