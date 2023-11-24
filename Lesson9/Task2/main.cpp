#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) { // проверка на успешное создание дочернего процесса
        std::cerr << "Ошибка при создании дочернего процесса" << std::endl;
        return 1;
    }
    else if (pid == 0) { // код выполняемый в дочернем процессе
        execlp("expr", "expr", "2", "+", "2", "*", "2", nullptr);
        std::cerr << "Ошибка при запуске команды" << std::endl;
        return 1;
    }
    else { // код выполняемый в родительском процессе
        wait(nullptr); // ожидание завершения дочернего процесса
        std::cout << "Дочерний процесс завершился" << std::endl;
    }

    return 0;
}

