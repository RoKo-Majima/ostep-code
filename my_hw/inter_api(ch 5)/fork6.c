#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    printf("Main pid: %d\n", (int) getpid());

    int pid = fork();
    if (pid < 0){
        printf("Fork failure\n");
        exit(1);
    }
    else if (pid == 0){
        int p = wait(NULL);
        printf("Hello from child process pid: %d, wait p: %d\n",
             (int) getpid(), p);
        //sleep(3);
        printf("I'm done\n");
    }
    else {
        printf("Waiting child process\n");
        int wait_var = waitpid(pid, NULL, 0);
        printf("Goodbye from parent process pid: %d, child pid: %d\n", (int)getpid(), pid);
        printf("Variable from wait(): %d\n", wait_var);
    //   size_t pid_size = sizeof(pid_t);
    //   printf("Size of pid_t: %lu\n", pid_size);
    }
    
    return 0;
} 