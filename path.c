#include "shell.h"

/**
 * find_command_path - searches through the directories to find a command
 * @command: command
 * Return: absolute path to the command if found, else NULL
 */
char *find_command_path(char **command)
{
	char *path_var = getenv("PATH"), *path_dir = NULL, *cmd_path = NULL;

	if (!command || !command[0])
		return (NULL);
	if (access(command[0], F_OK) == 0)
		return (strdup(command[0]));

	if (!path_var)
		return (NULL);
	path_dir = strtok(path_var, ":");
	if (!path_dir)
	{
		return (NULL);
	}
	while (path_dir)
	{
		cmd_path = malloc(1024);
		strcpy(cmd_path, path_dir);
		strcat(cmd_path, "/");
		strcat(cmd_path, command[0]);
		if (access(cmd_path, F_OK) == 0)
		{
			free(path_dir);
			return (cmd_path);
		}
		free(cmd_path);
		path_dir = strtok(NULL, ":");
	}
	return (NULL);
}
