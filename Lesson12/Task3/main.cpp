#include <iostream>
#include <limits>

int main()
{
    unsigned int max_unsigned_int = std::numeric_limits<unsigned int>::max();
    int max_int = static_cast<int>(max_unsigned_int);
    std::cout << "Максимальное значение типа unsigned int: " << max_unsigned_int << std::endl;
    std::cout << "Приведенное значение типа int: " << max_int << std::endl;
    return 0;

}

