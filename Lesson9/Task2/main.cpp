#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { 
        execlp("expr", "expr", "2", "+", "2", "*", "2", nullptr);
        exit(0);
    }
    else { 
        wait(nullptr); 
        std::cout << "Дочерний процесс завершился" << std::endl;
    }

    return 0;
}
