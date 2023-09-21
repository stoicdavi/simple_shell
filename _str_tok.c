#include "shell.h"

/**
 * _strtok - function to separate strings with delimiters
 * @line: the string to be separated.
 * @delim: characters to use as delimiters.
 * Return: pointer to the created token
 */
char *_strtok(char *line, char *delim)
{
	static char *str;
	char *copystr;
	int i = 0, b = 0;

	if (line != NULL)
		str = line;
	while (*str != '\0')
	{
		str++;
		for (b = 0; delim[b] != '\0'; b++)
		{
			if (*str == delim[b])
				break;
		}
		if (delim[b] == '\0')
			break;
	}
	copystr = str;

	if (*copystr == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		int b;

		for (b = 0; delim[b] != '\0'; b++)
		{
			if (str[i] == delim[b])
			{
				str[i] = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
