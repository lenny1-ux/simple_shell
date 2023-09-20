#include "shell.h"
#define MAX_INPUT_LENGTH 1024

int main(void) 
{
	char *input_buffer = NULL;
	size_t input_buffer_size = 0;

	while (1) {
    	// Print a simple prompt
    	printf("$ ");

    	// Read user input using getline
    	ssize_t input_length = getline(&input_buffer, &input_buffer_size, stdin);

    	if (input_length == -1) {
        	perror("getline");
        	exit(EXIT_FAILURE);
    	}

    	// Remove the newline character at the end
    	if (input_length > 0 && input_buffer[input_length - 1] == '\n') {
        	input_buffer[input_length - 1] = '\0';
    	}

    	// Tokenize the input to separate command and arguments
    	char *token = strtok(input_buffer, " ");
    	if (token == NULL) {
        	// Empty input, prompt again
        	continue;
    	}
	}
	free(input_buffer);
	return 0;
	}
