#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE

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

int execute(const char *filename, char *const argv[], char *const envp[]);
/**
 * struct var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct var_list
{
	int len_var;
	char *val;
	int len_val;
	struct var_list *next;
} var_lst;


#endif /*END OF SHELL.H*/
