#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
    // С использованием функции-обертки getpid из unistd.h
    pid_t pid1 = getpid();
    printf("PID using getpid(): %d\n", pid1);

    // С использованием универсальной функции-обертки syscall
    pid_t pid2 = syscall(SYS_getpid);
    printf("PID using syscall(): %d\n", pid2);

    // Проверка на идентичность возвращаемых значений
    if (pid1 == pid2) {
        printf("Both values are equal.\n");
    } else {
        printf("Values are different.\n");
    }

    return 0;
}

