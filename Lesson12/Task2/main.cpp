#include <iostream>

int main() {
    int a = 10;
    float b = 3.14;
    char c = 'A';

    std::cout << "&a: " << &a << std::endl;
    std::cout << "&b: " << &b << std::endl;
    std::cout << "&c: " << reinterpret_cast<void*>(&c) << std::endl;

    intptr_t addr_a = reinterpret_cast<intptr_t>(&a);
    intptr_t addr_b = reinterpret_cast<intptr_t>(&b);
    intptr_t addr_c = reinterpret_cast<intptr_t>(&c);

    
    std::cout << "addr_a" << ' ' << addr_a << std::endl;
    std::cout << "addr_b" << ' ' << addr_b << std::endl;
    std::cout << "addr_c" << ' ' << addr_c << std::endl;

    return 0;
}

