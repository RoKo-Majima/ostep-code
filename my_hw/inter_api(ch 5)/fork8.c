#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(void){
    int fd[2];
    pipe(fd);

    pid_t child1 = fork();

    if (child1 < 0){
        printf("Child1 fork fail\n");
        exit(1);
    } else if (child1 == 0) {
        close(fd[0]);
        write(fd[1], "hello", 5);
        close(fd[1]);
        exit(0);
    }

    pid_t child2 = fork();

    if (child2 < 0){
        printf("Child2 fork fail\n");
        exit(1);
    } else if (child2 == 0){
        close(fd[1]);
        char buff[100] = {0};
        int n = read(fd[0], buff, sizeof(buff));
        printf("Read numbers: %d\n", n);
        printf("Output: %s\n", buff);
        close(fd[0]);
        exit(0);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);

    return 0;
}