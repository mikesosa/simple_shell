#include "shell.h"
/**
 * _puts - function to print strings.
 * @str: the string
 *
 * Return: it returns the length of the string.
 */
void _puts(char *str)
{
	int x = 0;

	while (str[x])
		_putchar(str[x++]);
}
/**
 * _putchar - Fuction that prints to the std output
 * @c: char to print
 *
 * Return: the char printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
	memset(shell.command_line, 0, sizeof(shell.command_line));

	if (!shell.tty)
		return (false);

	shell.command_len = read(STDIN_FILENO, shell.command_line, MAX_LEN);
	deblank(); /* deleten spaces */

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
	static char buf[MAX_BUF_NOTTY] = {0};
	static int read_len, pos;
	int iline = 0;

	while (pos < read_len || (read_len = read(STDIN_FILENO, buf, sizeof(buf))))
	{
		while (pos < read_len && pos < MAX_BUF_NOTTY)
		{
			if (buf[pos] == '\n' || (pos == read_len - 1 && pos != MAX_BUF_NOTTY))
			{
				if (buf[pos] == '\n' && iline)
				{
					/* Returns when it finds a new line and it's not just a new line */
					shell.command_line[iline] = 0;
					deblank();
					pos++;
				}
				else if (!iline)
				{
					/* When it's just a new line */
					shell.command_line[0] = 0;
					pos += ++iline;
				}
				else
					/* when the entry does not end in line break */
					shell.command_line[iline] = buf[pos];

				return (iline);
			}
			shell.command_line[iline++] =  buf[pos++];
		}

		if (pos == MAX_BUF_NOTTY)
		{
			memset(buf, 0, read_len);
			pos = 0;
		}
	}

	return (false);
}
