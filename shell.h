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

int execute(const char *filename, char *const argv[], char *const envp[]);
bool prog_Exists(const char *filename);

int check_file(char *full_path);

char *_strcpy(char *dest, char *src, int n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

char *_strtok(char *line, char *delim);

#endif /*END OF SHELL.H*/
