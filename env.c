#include "shell.h"
/**
 * _getenv - get an environment variable
 * @name: missing variable
 *
 * Return: address of the variable
*/
char *_getenv(char *name)
{
	char *key, *value = NULL;
	int i = 0;

	for (i = 0; __environ[i]; i++)
	{
		key = strtok(__environ[i], "=\n");

		if (!_strcmp(key, name))
		{
			value = strtok(NULL, "=\n");
			break;
		}

		key[_strlen(key)] = '=';
	}

	key[_strlen(key)] = '=';
	return (value);
}
