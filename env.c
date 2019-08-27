#include "shell.h"
/**
 * _getenv - get an environment variable
 * @name: missing variable
 *
 * Return: address of the variable
*/
char *_getenv(const char *name)
{
	char *key = NULL, *value = NULL;
	int i = 0;

	for (i = 0; __environ[i]; i++)
	{
		key = _strtok(__environ[i], "=\n");

		if (!_strcmp(key, name))
		{
			value = _strtok(NULL, "=\n");
			break;
		}

		if (key)
			key[_strlen(key)] = '=';
	}

	if (key)
		key[_strlen(key)] = '=';

	return (value);
}
