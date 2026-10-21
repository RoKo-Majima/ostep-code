#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void){
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failure\n");
        exit(1);
    }
    else if (pid == 0){
        // Child process
        char *argv[3];
        argv[0] = "ls";
        argv[1] = "-la";
        argv[2] = NULL;
        char *argenv[3];
        argenv[0] = "MY_VAR=Roman";
        argenv[1] = "COURSE=OSTEP";
        argenv[2] = NULL;
        printf("Hello from child process!\n");
        //execl("/bin/ls", "ls", "-la", NULL);
        //execl(argv[0], argv[1], argv[2], NULL);
        //execv("/bin/ls", argv);
        //execlp("ls", "ls", "-la", NULL);
        //execvp("ls", argv);
        execve("/bin/ls", argv, argenv);
        printf("This line should not be printed if exec is successful.\n");
    }
    else {
        // Parent process
        wait(NULL);
        printf("Goodbye from parent process!\n");
    }

    return 0;
}