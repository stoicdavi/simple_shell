#include "shell.h"
/**
 * _strcat - function to combine two strings
 * @dest: destination string where the result of concat will be stored
 * @src: string that will be appended to dest
 * Return: pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int destInd = 0, srcInd = 0;

	while (dest[destInd] != '\0')
		destInd++;
	while (src[srcInd] != '\0')
	{
		dest[destInd] = src[srcInd];
		destInd++;
		srcInd++;
	}
	dest[destInd] = '\0';
	return (dest);
}
/**
 * _strcpy - function to copy src string to dest string
 * @dest: holds to string coppied
 * @src: holds the string to be coppied
 * @n: size of the string
 * Return: pointer to the updated string after copying (dest)
 */
char *_strcpy(char *dest, char *src, int n)
{
	int a = 0;

	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
/**
 * _strdup - function to duplicate mem by malloc for the duplic and
 * copy the content of the src to the duplic
 * @str: stores the src string to be coppied to the duplic
 * Return: pointer to the duplicate
 */
char *_strdup(char *str)
{
	char *ptr_alloc, *ptr_alloc_char;
	size_t len = 0;

	if (str == NULL)
		return (NULL);

	for (; str[len]; len++)
		;
	ptr_alloc = malloc(sizeof(char) * len + 1);

	if (ptr_alloc == NULL)
		return (NULL);
	ptr_alloc_char = ptr_alloc;

	while (*str)
	{
		*ptr_alloc_char = *str;
		str++;
		ptr_alloc_char++;
	}
	*ptr_alloc_char = '\0';
	return (ptr_alloc);
}

/**
 * _strcmp - function to compare two compares 2 strings
 * @s1: first string to be compared with s2
 * @s2: second string compared to be compred with s2
 * Return: 0 if equal, positive if s1 is less than
 * s2, negative if s1 greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strlen - returns the lenth of a string
 * @s: The string to be checked for length
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
