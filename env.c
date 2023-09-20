#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to handle the "env" command
void print_environment() {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

int main() {
    char input[1024];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        // Remove newline character from input
        input[strlen(input) - 1] = '\0';

        // Check for the "env" command
        if (strcmp(input, "env") == 0) {
            print_environment();
        } else if (strcmp(input, "exit") == 0) {
            // Exit the shell when the user enters "exit"
            break;
        } else {
            // Execute other commands (not implemented in this basic example)
            printf("Command not found: %s\n", input);
        }
    }

    return 0;
}

