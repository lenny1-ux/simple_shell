#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " \n\t");

    while (token != NULL && i < MAX_ARG_SIZE - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n\t");
    }

    args[i] = NULL;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];

    while (1) {
        printf("SimpleShell> ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            perror("Failed to read input");
            exit(EXIT_FAILURE);
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Check for exit command
        if (strcmp(input, "exit") == 0)
            break;

        // Fork and execute
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process

            // Parse the input into arguments
            parse_input(input, args);

            // Iterate over the PATH directories and attempt to execute the command
            char *path = getenv("PATH");
            char *path_copy = strdup(path); // Make a copy to avoid modifying the original
            char *dir = strtok(path_copy, ":");
            while (dir != NULL) {
                char executable[MAX_INPUT_SIZE];
                snprintf(executable, sizeof(executable), "%s/%s", dir, args[0]);
                if (access(executable, X_OK) == 0) {
                    execv(executable, args);
                    perror("Execution failed");
                    exit(EXIT_FAILURE);
                }
                dir = strtok(NULL, ":");
            }

            // If the command was not found in any PATH directory
            printf("Command not found: %s\n", args[0]);
            free(path_copy);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

