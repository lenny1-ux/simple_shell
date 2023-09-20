#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        // Display a prompt
        printf("simple_shell> ");

        // Read a command from the user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle Ctrl+D (EOF)
            printf("\n");
            break;
        }

        // Remove the trailing newline character
        input[strlen(input) - 1] = '\0';

        // Create a child process
        pid_t pid = fork();

        if (pid == -1) {
            // Error occurred while forking
            perror("fork");
        } else if (pid == 0) {
            // Child process
            // Execute the command using execlp
            if (execlp(input, input, NULL) == -1) {
                // Handle command not found error
                printf("Command not found: %s\n", input);
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            int status;
            // Wait for the child to complete
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
            }
        }
    }

    return 0;
}

