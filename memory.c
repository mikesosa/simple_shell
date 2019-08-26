#include "shell.h"
/**
 * free_args - function that frees memory allocations
 * @shell: global struct shell
 *
 * Reeturn: void
 */
void free_args(shell_t *shell)
{
	int i = 0;

	for (; shell->argv[i]; i++)
	{
		free(shell->argv[i]);
		shell->argv[i] = NULL;
	}
}
/**
 * _memset - fill memory with a constant byte
 * @s: buffer to set
 * @c: constant byte to write
 * @n: count
 *
 * Return: address of @s
 */
void *_memset(void *s, int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		((char *)s)[i] = c;

	return (s);
}
