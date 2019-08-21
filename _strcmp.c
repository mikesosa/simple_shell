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

int _strcmp(char *s1, char *s2)
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
