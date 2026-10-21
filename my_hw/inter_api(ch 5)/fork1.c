#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This program demonstrates the use of fork() to create a child process.
// The parent and child processes will have their own copies of the variable x.

int main(void) {
    int x = 1000;
    int pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        x += 500;
        printf("Child process: x = %d\n", x);
    } else {
        // Parent process
        x = 100;
        x += 500;
        printf("Parent process: x = %d\n", x);
    }

    return 0;
}