#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>

extern char **environ;

int main() {
    // Выполняем цикл по всем переменным среды
    for(int i = 0; environ[i] != NULL; i++) {
        char* env = environ[i]; // Текущая переменная среды

        // Проверяем, содержит ли имя переменной символ L
        if(strchr(env, 'L') != NULL) {
            printf("%s\n", env); // Выводим переменную среды
        }
    }

    return 0;
}


