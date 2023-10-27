#include <iostream>

// Проверяем наличие макросов USE_GPU и USE_FLOAT
#if defined(USE_GPU) && defined(USE_FLOAT)
    // Версия кода 1: USE_GPU и USE_FLOAT определены
    #define CODE_VERSION 1
#elif defined(USE_GPU)
    // Версия кода 2: USE_GPU определен, USE_FLOAT не определен
    #define CODE_VERSION 2
#elif defined(USE_FLOAT)
    // Версия кода 3: USE_FLOAT определен, USE_GPU не определен
    #define CODE_VERSION 3
#else
    // Версия кода 4: Ни USE_GPU, ни USE_FLOAT не определены
    #define CODE_VERSION 4
#endif

int main() {
    // В зависимости от версии кода, выводим соответствующее сообщение
    #if CODE_VERSION == 1
        std::cout << "Используется версия кода 1 (USE_GPU и USE_FLOAT определены)." << std::endl;
    #elif CODE_VERSION == 2
        std::cout << "Используется версия кода 2 (USE_GPU определен, USE_FLOAT не определен)." << std::endl;
    #elif CODE_VERSION == 3
        std::cout << "Используется версия кода 3 (USE_FLOAT определен, USE_GPU не определен)." << std::endl;
    #elif CODE_VERSION == 4
        std::cout << "Используется версия кода 4 (USE_GPU и USE_FLOAT не определены)." << std::endl;
    #else
        std::cout << "Неизвестная версия кода." << std::endl;
    #endif

    return 0;
}

