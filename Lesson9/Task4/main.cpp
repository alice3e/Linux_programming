#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <sys/types.h>

const int STACK_SIZE = 65536;

// Функция, которую будет выполнять дочерний процесс после вызова clone
int childFunction(void* arg) {
    char* newHostname = reinterpret_cast<char*>(arg);

    // Изменяем имя компьютера
    if (sethostname(newHostname, std::strlen(newHostname)) == -1) {
        perror("sethostname");
        return -1;
    }

    // Проверяем изменение имени компьютера
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname");
        return -1;
    }

    std::cout << "Child process - Hostname: " << hostname << std::endl;

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <new_hostname>" << std::endl;
        return 1;
    }

    // Создаем массив стека для дочернего процесса
    char* childStack = new char[STACK_SIZE];

    // Создаем дочерний процесс с помощью clone
    pid_t pid = clone(childFunction, childStack + STACK_SIZE, CLONE_NEWUTS | SIGCHLD, argv[1]);

    if (pid == -1) {
        perror("clone");
        return 1;
    }

    // Ждем завершения дочернего процесса
    if (waitpid(pid, nullptr, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    // Проверяем имя компьютера в родительском процессе
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname");
        return 1;
    }

    std::cout << "Parent process - Hostname: " << hostname << std::endl;

    delete[] childStack;

    return 0;
}

