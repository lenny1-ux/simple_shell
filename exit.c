#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

void exit_shell() {
    printf("Exiting the shell.\n");
    exit(0);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Shell> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check for the exit command
        if (strcmp(input, "exit") == 0) {
            exit_shell();
        } else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}

