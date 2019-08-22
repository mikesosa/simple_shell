#include "shell.h"

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
