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
