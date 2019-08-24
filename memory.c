#include "shell.h"
/**
 * free_args - function that frees memory allocations
 */
void free_args(void)
{
	int i = 0;

	if (!shell.tty)
		i = 1;

	for (; shell.argv[i]; i++)
		free(shell.argv[i]);
}