#include "shell.h"
/**
 * *_strtok - tokenize a string in an array depending on delim
 * @s: String to tokenize
 * @delim: string used as delimiter
 *
 * Return: the new value of s.
 */
char *_strtok(char *s, const char *delim)
{
	char *end;
	static char *save_ptr;

	if (s == NULL)
		s = save_ptr;

	if (*s == '\0')
	{
		save_ptr = s;
		return (NULL);
	}

	/* Scan leading delimiters.  */
	s += _strspn(s, delim);
	if (*s == '\0')
	{
		save_ptr = s;
		return (NULL);
	}

	/* Find the end of the token.  */
	end = s + _strcspn(s, delim);
	if (*end == '\0')
	{
		save_ptr = end;
		return (s);
	}

	/* Terminate the token and make SAVE_PTR point past it.  */
	*end = '\0';
	save_ptr = end + 1;
	return (s);
}
/**
 * *_strcspn - finding a char in an array
 * @s: source
 * @reject: character rejected for the function
 *
 * Return: the new value of s.
 */
size_t _strcspn(char *s, const char *reject)
{
	int i = 0, counter = 0;

	while (s[i]  != '\0')
	{
		if (s[i] == *reject)
			break;
		counter++;
		i++;
	}
	return (counter);
}
/**
 * *_strspn - finding a char in an array
 * @s: source
 * @accept: the only chars accepted
 * Return: the new value of s.
 */
size_t _strspn(char *s, const char *accept)
{
	int i, j, c = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				c++;
				break;
			}
		}
		if (accept[j] == '\0')
			break;
	}
	return (c);
}
