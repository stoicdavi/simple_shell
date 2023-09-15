#include "shell.h"
/**
 * main -  entry point to the function
 * @ac: argument count
 * @av: argument value
 * @envar: array value from the environment
 * Return: 0 on success
 */
int main(int ac, char *av[], char **envar)
{
	char *buff = NULL;
	char *prompt = "$ ";
	size_t buff_size = 0, bytes;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		write(STDOUT_FILENO, prompt, 2);
		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error getline failed");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (buff[bytes - 1] == '\n')
			buff[bytes - 1] = '\0';
		wpid = fork();
		if (wpid == -1)
		{
			perror("Error: fork failed");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (wpid == 0)/*child process*/
			execute(buff, av, envar);
		else
			if (waitpid(wpid, &wstatus, 0) == -1)/*parent process*/
			{
				perror("Error waiting failed");
				free(buff);
				exit(EXIT_FAILURE);
			}
	}
	free(buff);
	return (0);
}
/**
 * execute - function to check if the function exists
 * @filename: the file to be checked
 * @argv: argument value
 * @envp: environment value
 * Return: execution status
 */
int execute(const char *filename, char *const argv[], char *const envp[])
{

	int exec_status = execve(filename, argv, envp);

	if (exec_status == -1)
	{
		perror("Simple_shell");
	}
	return (exec_status);
}
