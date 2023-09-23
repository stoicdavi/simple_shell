#include "shell.h"
/**
 * isInputInteractive - Checks if the program
 * is running interactively.
 *
 * Return: 1 if running interactively, 0 if running non-interactively.
 */
int isInputInteractive(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
