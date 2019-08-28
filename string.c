#include "shell.h"
/**
 * _strcmp - compares s1 and s2
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: Negative integer is s1 belongs before s2.
 * 0 if s1 and s2 are the same
 * Positive integer if s1 belongs after s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			break;
		i++;
	}

	return (s1[i] - s2[i]);
}
/**
 * *_strcpy - pasing values to other array
 * @dest: Destiny
 * @src: Soure
 *
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0' ; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';
	return (dest);
}
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
/**
 * _strlen - lenght of a string
 * @s: string to count
 *
 * Return: lenght of a string
 */
int _strlen(char *s)
{
	if (!*s)
		return (0);

	return (1 + _strlen(s + 1));
}
/**
 * deblank - delete unnecessary spaces in the string
 * @shell: global struct shell
 *
 * Return: void
 */
void deblank(shell_t *shell)
{
	char *buffer;
	int i = 0, j = 0;

	buffer = shell->command_line;

	if (buffer[i] == 32 || buffer[i] == 9)
	{
		while (buffer[i] == 32 || buffer[i] == 9)
		{
			i++;
		}
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			i++;
			j++;
		}
		while (buffer[j] != '\0')
		{
			buffer[j] = '\0';
		}
	}
}
