#include "shell.h"

/**
 * *_strdup - copies an string to an array
 * @s: Source string
 *
 * Return: @dest which is the new memory location.
 */
char *_strdup(char *s)
{
	char *dest;
	int i = 0;

	if (s == NULL)
		return (NULL);

	while (s[i])
		i++;

	dest = malloc(sizeof(char) * i + 1);

	if (dest == NULL)
		return (NULL);

	i = 0;

	for (i = 0; s[i]; i++)
		dest[i] = s[i];

	dest[i] = s[i];
	return (dest);
}
