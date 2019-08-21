#include "shell.h"

/**
 * signal_killer - takes signals and perform print_prompt again
 * @n: type of signal, in this case SIGINT is equivalent to 2
 * Return: void
 */
void signal_killer(int n)
{
	(void) n;

	write(STDOUT_FILENO, "\n", 1);
	print_prompt_tty();
}
