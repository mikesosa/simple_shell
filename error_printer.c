#include "shell.h"

/**
 * error_printer - helps with printing errors
 * @command: command to print
 * @to_print: string to print
 *
 * Descrption: We can always update this
 */
void error_printer(char *command, char *to_print)
{
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, to_print, _strlen(to_print));
}
