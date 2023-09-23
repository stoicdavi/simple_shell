#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
void free_array(char **arr);
int exit_shell(char *exit_status);

char *_strcpy(char *nest, char *src, int n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int isInputInteractive(void);
char *_strtok(char *line, char *delim);

extern int status;
extern char *line;
extern char **command;
extern int shell_count;
extern char *shell;
#endif /*END OF SHELL.H*/
