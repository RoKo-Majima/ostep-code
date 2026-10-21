#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
    pid_t child = fork();
    if (child < 0){
        printf("Fork fail\n");
        exit(1);
    }
    else if (child == 0){
        printf("Hello, this is child process\n");
        close(STDOUT_FILENO);
        if (printf("test\n") < 0)
            perror("printf");
        open("./fork7.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
                printf("STDOUT closed\n");


    }
    else {
        printf("Goodbye from parent process\n");
    }

    return 0;
}