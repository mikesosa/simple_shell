#include "shell.h"

/**
 * signal_killer - takes signals and perform print_prompt again
 * @n: type of signal, in this case SIGINT is equivalent to 2
 *
 * Return: void
 */

void signal_killer(__attribute((unused))int n)
{
	write(STDOUT_FILENO, "\n", 2); /* Write a new line if ctrl+c */
	print_prompt_tty(NULL); /* Print prompt again */
}
