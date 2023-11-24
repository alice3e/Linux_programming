#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <new_hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *new_hostname = argv[1];

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Код, выполняемый в дочернем процессе
        if (sethostname(new_hostname, strlen(new_hostname)) == -1) {
            perror("sethostname");
            exit(EXIT_FAILURE);
        }

        // Печать имени компьютера в дочернем процессе
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == -1) {
            perror("gethostname");
            exit(EXIT_FAILURE);
        }
        printf("Child Hostname: %s\n", hostname);

        exit(EXIT_SUCCESS);
    } else {
        // Код, выполняемый в родительском процессе
        int status;
        waitpid(pid, &status, 0);

        // Печать имени компьютера в родительском процессе
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == -1) {
            perror("gethostname");
            exit(EXIT_FAILURE);
        }
        printf("Parent Hostname: %s\n", hostname);
    }

    return 0;
}

