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
	write(STDERR_FILENO, shell->argv[0], _strlen(shell->argv[0]));
	write(STDERR_FILENO, ": not found\n", 13);
	errno = 0;
}

/**
 * _pexit - print exits
 * @shell: global struct shell
 *
 * Return: void
 */
void _pexit(shell_t *shell)
{
	itoa(shell->count_commands, shell->buf_itoa);

	/* Print error if command doesn't exist */
	write(STDERR_FILENO, shell->name, _strlen((char *)shell->name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, shell->buf_itoa, _strlen(shell->buf_itoa));
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);
	write(STDERR_FILENO, shell->argv[1], _strlen(shell->argv[1]));
	write(STDERR_FILENO, "\n", 1);
}
