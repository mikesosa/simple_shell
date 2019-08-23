#include "shell.h"

/**
 * _readline - reads the entire line of strings passed to our shell
 *
 * Descrption: This is our own version of the function getline()
 * we use read to read from the stdin, we save the string in command_line
 * and the bytes read in command_len.
 *
 * Return: @true if was possible to read @false if fails.
 */
int _readline(void)
{
	char buf[1]; /*This will always keep one char at a time*/
	int i = 0; /*interates our command_line*/
	int x = 0; /*stores the result of read, must be always 1 if dont EOF*/

	if (!shell.tty)
		return (false);

	/*reading byte by byte*/
	while ((x = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
	{
		shell.command_line[i] = buf[0];/*saves char by char in command_line*/
		if (buf[0] == '\n' && i == 0)/*if enter is pressed and nothing else*/
			break;
		else if (buf[0] == '\n')/*if enter is pressed set last byte to zero*/
		{
			shell.command_line[i] = 0;
			break;
		}
       i++;
	}
	if(x == 0)/*if x is 0 means reading wasnt possible*/
		return (false); /* EOF - Ctrl+D */
    deblank(shell.command_line); /*deleten spaces*/

	/*DANI: Do we need this?*/
	shell.command_len = _strlen(shell.command_line);

	return (true);
}
