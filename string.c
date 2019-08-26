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
 * @src: Soure
 * @dest: Destiny
 * Return: Void;
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
	char *input = shell->command_line;
	int i, j;

	for (i = 0, j = 0; i < _strlen(input); i++, j++)
	{
		if (input[i] != ' ')
		{
			/* If its an space put it and later we will overwrite tht */
			input[j] = input[i];

			if (input[i + 1] == ' ')
				input[++j] = input[++i];
		}
		else
			j--;
	}

	input[j - ((shell->tty & 1) ? 1 : 0)] = '\0';
}
