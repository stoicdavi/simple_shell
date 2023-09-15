#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

#endif /*END OF SHELL.H*/
