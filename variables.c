#include "shell.h"

/**
 * itoa - convert integer to string
 * @n: integer
 * @s: char array
 *
 * Return: returns int for position of format
 */
int itoa(int n, char s[])
{
	int i = 0;

	if (n / 10 != 0)
		i = itoa(n / 10, s);
	else if (n < 0)
		s[i++] = '-';

	if (n < 0)
		n = ~n + 1;

	s[i++] = (n % 10) + '0';
	s[i] = '\0';

	return (i);
}

/**
 * variable_handler - replace arguments with variables
 * @shell: global shell struct
 * @index: index in argv of the shell
 *
 * Return: void
 */
void variable_handler(shell_t *shell, size_t index)
{
	char buf[120] = {0};

	if (!_strcmp("$$", shell->argv[index]))
		itoa(getpid(), buf);

	else if (!_strcmp("$?", shell->argv[index]))
		itoa(shell->exit_code_child, buf);

	free(shell->argv[index]);
	shell->argv[index] = _strdup(buf);
}

/**
 * variables - search variables in arguments
 * @shell: global shell struct
 *
 * Return: void
 */
void variables(shell_t *shell)
{
	int i, j;

	char *variables_list[] = {
		"$$", /* process id */
		"$?", /* exit code child's */
		NULL
	};
	for (i = 0; variables_list[i]; i++)
	{
		for (j = 0; shell->argv[j]; j++)
		{
			if (!_strcmp(variables_list[i], shell->argv[j]))
			{
				variable_handler(shell, j);
				return;
			}
		}
	}
}
