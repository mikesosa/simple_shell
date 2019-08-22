#include "shell.h"

/**
 * _getline - reads the entire line of strings passed to our shell
 *
 * Descrption: This is our own version of the function getline()
 * we use read to read from the stdin, we save the string in command_line
 * and the bytes read in command_len.
 *
 * Return: @true if was possible to read @false if fails.
 */
int _getline(void)
{
	shell.command_len = read(STDIN_FILENO, shell.command_line, MAX_LEN);

	/* If read success */
	if (shell.command_len)
	{
		/* We end the string with a 0 only if user doesn't */
		/* Enter a new line '\n' */
		if (shell.command_line[0] != '\n')
			shell.command_line[shell.command_len - 1] = 0;
	}
	else
		return (false); /* EOF - Ctrl+D */

	return (true);
}
