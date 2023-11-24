#include <iostream>
#include <limits>

int main()
{
    unsigned int max_unsigned_int = std::numeric_limits<unsigned int>::max();
    int max_int = static_cast<int>(max_unsigned_int);
    std::cout << "Максимальное значение типа unsigned int: " << max_unsigned_int << std::endl;
    std::cout << "Приведенное значение типа int: " << max_int << std::endl;
    return 0;
    
    // int max_int = std::numeric_limits<int>::max();
    // unsigned int max_unsigned_int = static_cast<unsigned int>(max_int);
    // std::cout << "Максимальное значение типа int: " << max_int << std::endl;
    // std::cout << "Приведенное значение типа unsigned int: " << max_unsigned_int << std::endl;
    // return 0;
    
}

