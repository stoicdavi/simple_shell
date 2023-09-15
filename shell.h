#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

typedef struct passinfo
{
	char *arg;
	char **argv;
	int argc;
	int readfd;
} info_t;

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

#endif /*END OF SHELL.H*/
