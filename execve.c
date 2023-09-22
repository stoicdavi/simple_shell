#include "shell.h"
/**
  * isExecutable -checks if the command is executable
  * @commandArgs: An array of command arguments
  * Return: treu is executable, false otherwise
  */
bool isExecutable(char **commandArgs)
{
	char *pathVariable = getenv("PATH");
	char *pathToken = strtok(pathVariable, ":");

	while (pathToken != NULL)
	{
		char *fullPath = malloc(strlen(pathToken) + strlen(commandArgs[0]) + 2);

		strcpy(fullPath, pathToken);
		strcat(fullPath, "/");
		strcat(fullPath, commandArgs[0]);

		if (access(fullPath, X_OK) == 0)
		{
			free(fullPath);
			return (true);
		}
		free(fullPath);
		pathToken = strtok(NULL, ":");
	}
	return (false);
}

