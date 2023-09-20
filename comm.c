#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("SimpleShell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Exit the shell if the user enters "exit"
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the shell.\n");
            break;
        }

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // This is the child process
            char* args[MAX_INPUT_SIZE];
            int i = 0;
            char* token = strtok(input, " ");

            while (token != NULL) {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }

            args[i] = NULL; // Null-terminate the argument list

            // Execute the command
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
        } else {
            // This is the parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Child process did not exit normally\n");
            }
        }
    }

    return 0;
}

