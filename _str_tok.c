#include "shell.h"

/**
 * _strtok - funtion to separate strings with delimiters
 * @line: the string to be separated.
 * @delim: to separate the strings.
 * Return: pointer to the created token
 */
char *_strtok(char *line, char *delim)
{
	int a;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
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
	for (; *str != '\0'; str++)
	{
		for (b = 0; delim[b] != '\0'; b++)
		{
			if (*str == delim[b])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
