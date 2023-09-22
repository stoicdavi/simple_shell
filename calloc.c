#include "shell.h"
/**
 * _calloc - allocates memory to an array
 * @nmemb: number of array elements
 * @size: size of bytes to be alloctated to each nmemb elements
 * Return: a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr_alloc;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	arr_alloc = malloc(nmemb * size);
	if (!arr_alloc)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		((char *) (arr_alloc))[i] = 0;
	return (arr_alloc);
}
/**
 * _getline - Reads a line of text from standard
 * input and stores it in a buffer.
 * @line: Pointer to the buffer where the line will be stored.
 *
 * Return: Number of characters read, or -1 on error.
 */
ssize_t _getline(char **line)
{
	char *buffer = _calloc(8096, sizeof(char));
	ssize_t characters_read = 0;

	if (!buffer)
		exit(EXIT_FAILURE);

	while ((read(0, &buffer[characters_read], 1)) > 0
			&& (buffer[characters_read] != '\n'))
		characters_read++;

	if (buffer[characters_read] == '\n')
	{
		*line = malloc(sizeof(char) * (characters_read + 1));
		if (!*line)
			exit(EXIT_FAILURE);
		buffer[characters_read] = '\0';
		_strcpy(*line, buffer, characters_read + 1);
		free(buffer);
		return (characters_read);
	}
	else if (characters_read != 0)
	{
		buffer[characters_read] = '\0';
		*line = malloc(sizeof(char) * (characters_read + 1));
		if (!*line)
			exit(EXIT_FAILURE);
		_strcpy(*line, buffer, characters_read + 1);
		free(buffer);
		return (-1);
	}
	else
	{
		if (isatty(0))
			printf("\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
}
