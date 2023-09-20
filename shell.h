#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

int _putchar(char c);
int exist(char *pathname);
void free_grid(char **grid, int heigth);
void last_free(char *entry);
int verify_blt(char **arguments, int exit_stat);
char *append_command(char *dir_path, char *command);
int exec(char **arguments);
int fill_args(char *entry, char **arguments);
int print_numbers(int n);
int _strlen(const char *string);
int print_not_found(char **arguments, int counter);
char *_getenv(char *global_var);
int _printp(const char *prompt, unsigned int size);
extern char **environ;
int _strcmp(char *str1, char *str2);
int verify_path(char **arguments);
char *_strdup(char *str);
#endif

