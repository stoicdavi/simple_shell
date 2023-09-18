#include "shell.h"
/**
 * prog_Exists - function chesks whether the given path exists
 * @filename: name of the specified file
 * Return: false if the program doesn't exist
 */
bool prog_Exists(const char *filename)
{
	if (access(filename, X_OK) == 0)
	{
		return (true);
	}
	perror("No such file");
	return (false);
}
