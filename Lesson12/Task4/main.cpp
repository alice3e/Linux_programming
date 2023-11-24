#include<iostream>

int main() {
    int num = 12345678; // Пример значения переменной int

    // Вывод побайтового значения со знаком плюс
    unsigned char* bytePlus = reinterpret_cast<unsigned char*>(&num);
    for (int i = 0; i < sizeof(int); i++) {
        std::cout << "+" << static_cast<int>(bytePlus[i]) << " ";
    }
    std::cout << std::endl;

    // Вывод побайтового значения со знаком минус
    signed char* byteMinus = reinterpret_cast<signed char*>(&num);
    for (int i = 0; i < sizeof(int); i++) {
        std::cout << static_cast<int>(byteMinus[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}

