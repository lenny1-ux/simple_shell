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

int main(void);
/* builtins cmds */
void execute_cd(char *args[]);
void execute_exit(void);
void execute_history(void);
void execute_ls(void);
int envn(char **env);
void env_path(void);



#endif

