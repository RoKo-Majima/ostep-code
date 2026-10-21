#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int fd = open("fork2_output.txt", O_RDWR | O_CREAT, 0644);

    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        const char *child_msg = "Hello!\n";
        write(fd, child_msg, strlen(child_msg));
        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        sleep(5); // Wait for the child process to finish
        const char *parent_msg = "Goodbye!\n";
        write(fd, parent_msg, strlen(parent_msg));
        close(fd);
    }


    return 0;
}