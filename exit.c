#include "shell.h"
/**
 * exit_shell - exit shell
 * @exit_status: status
 * Return: 2 on success
 */
int exit_shell(char *exit_status)
{
	int status = 0;
	char *line = NULL, **command = NULL;

	if (!exit_status)
	{
		free(line);
		free_array(command);
		exit(status);
	}
	status = atoi(exit_status);
	if (status >= 0)
	{
		free(line);
		free_array(command);
		exit(status);
	}
	fprintf(stderr, "exit: ");
	fprintf(stderr, "Illegal number: %s\n", exit_status);
	return (2);
}
/**
 * free_array - a function that frees the memory allocated to an array
 * @arr: the array to be freed
 */
void free_array(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}
