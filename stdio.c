#include "shell.h"
/**
 * _puts - function to print strings.
 * @str: the string
 *
 * Return: it returns the length of the string.
 */
void _puts(const char *str)
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
 * @shell: global struct shell
 *
 * Descrption: This is our own version of the function getline()
 * we use read to read from the stdin, we save the string in command_line
 * and the bytes read in command_len.
 *
 * Return: @true if was possible to read @false if fails.
 */
int _readline(shell_t *shell)
{
	_memset(shell->command_line, 0, sizeof(shell->command_line));

	shell->command_len = read(STDIN_FILENO, shell->command_line, MAX_LEN);
	deblank(shell); /* deleten spaces */

	/* If read success */
	if (shell->command_len)
	{
		/* We end the string with a 0 only if user doesn't */
		/* Enter a new line '\n' */
		if (shell->command_line[0] != '\n')
			shell->command_line[shell->command_len - 1] = 0;
	}
	else
		return (false); /* EOF - Ctrl+D */

	return (true);
}
/**
 * _getline - reads the entire line of strings passed to our shell
 * @shell: global struct shell
 *
 * Descrption: This is our own version of the function getline()
 * we use read to read from the stdin, we save the string in command_line
 * and the bytes read in command_len.
 *
 * Return: @true if was possible to read @false if fails.
 */
int _getline(shell_t *shell)
{
	static char buf[MAX_BUF_NOTTY] = {0};
	int fd = STDIN_FILENO;
	static int len, pos;
	int iline = 0;

	if (shell->main_argv[1])
		fd = open(shell->main_argv[1], O_RDWR);
	while (fd != -1 && (pos < len || (len = read(fd, buf, sizeof(buf)))))
	{
		while (pos < len && pos < MAX_BUF_NOTTY)
		{
			if (buf[pos] == '\n' || (pos == len - 1 && pos != MAX_BUF_NOTTY))
			{
				if (buf[pos] == '\n' && iline)
				{
					shell->command_line[iline] = 0;
					deblank(shell);
					pos++;
				}
				else if (!iline)
				{
					shell->command_line[0] = 0; /* When it's just a new line */
					pos += ++iline;
				}
				else
					shell->command_line[iline] = buf[pos];
				return (iline);
			}
			shell->command_line[iline++] =  buf[pos++];
		}
		if (pos == MAX_BUF_NOTTY)
		{
			_memset(buf, 0, len);
			pos = 0;
		}
	}
	return (false);
}
