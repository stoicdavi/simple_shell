#include "shell.h"
/**
 * executeCommand - to chech child and parent process
 * @args: arguments
 * @background: status
 *
 */
void executeCommand(char **args, int background)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		if (!background)
		{
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
