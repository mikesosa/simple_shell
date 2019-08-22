#include "shell.h"

/**
 * _strlen - lenght of a string
 * @s: string to count
 *
 * Return: lenght of a string
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

