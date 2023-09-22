#include "shell.h"

/**
 * main - entry point
 *
 * Return: always 0 on success
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH], *args[MAX_ARGS], *token;
	int  num_args = 0, status;
	pid_t pid;

	while (1)
	{
		if (isInputInteractive())
			printf("$ ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';
		token = strtok(input, " ");
		num_args = 0;
		while (token != NULL && num_args < MAX_ARGS)
		{
			args[num_args++] = token;
			token = strtok(NULL, " ");
		}
		args[num_args] = NULL;
		if (num_args == 0)
		{
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			printf("Exiting the shell.\n");
			break;
		}
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
			waitpid(pid, &status, 0);
		else
			perror("fork");
	}
	return (0);
}
