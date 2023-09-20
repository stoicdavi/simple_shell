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


#endif /*END OF SHELL.H*/
