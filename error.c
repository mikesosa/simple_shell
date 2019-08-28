#include "shell.h"

/**
 * _perror - print errors
 * @shell: global struct shell
 *
 * Return: void
 */
void _perror(shell_t *shell)
{
	itoa(shell->count_commands, shell->buf_itoa);

	/* Print error if command doesn't exist */
	write(STDERR_FILENO, shell->name, _strlen((char *)shell->name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, shell->buf_itoa, _strlen(shell->buf_itoa));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, shell->command, _strlen(shell->command));
	write(STDERR_FILENO, ": not found\n", 13);
	errno = 0;
}