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
	char *buff = NULL, *prompt = "$ ";
	size_t buff_size = 0;
	int bytes;
	pid_t pid;
	int wstatus;
	bool from_pipe = true;
	(void) ac;

	while (1 && from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = false;
		write(STDOUT_FILENO, prompt, 2);
		bytes = getline(&buff, &buff_size, stdin);
		if (bytes <= 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (buff[bytes - 1] == '\n')
			buff[bytes - 1] = '\0';
		if (strcmp(buff, "exit") == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			perror("Error: fork failed");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)/*child process*/
			execute(buff, av, envar);
		else
			if (waitpid(pid, &wstatus, 0) == -1)/*parent process*/
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
 * @argv: array of command line argument
 * @envp: array of environmrnt variable for the new program
 * Return: execution status
 */
int execute(const char *filename, char *const argv[], char *const envp[])
{

	int exec_status = execve(filename, argv, envp);

	if (exec_status == -1)
	{
		perror("./shell");
	}
	exit(EXIT_FAILURE);
}
