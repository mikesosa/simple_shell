#include "shell.h"

/**
 * deblank - delete unnecessary spaces in the command
 *
 * Return: void
 */
void deblank(void)
{
	char *input = shell.command_line;
	int i, j;

	for (i = 0, j = 0; i < _strlen(input); i++, j++)
	{
		if (input[i] != ' ')
		{
			/* If its an space put it and later we will overwrite tht */
			input[j] = input[i];

			if (input[i + 1] == ' ')
				input[++j] = input[++i];
		}
		else
			j--;
	}

	input[j - ((shell.tty) ? 1 : 0)] = '\0';
}
