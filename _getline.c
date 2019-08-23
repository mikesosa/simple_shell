#include "shell.h"
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
		for (; pos < read_len && pos < MAX_BUF_NOTTY; pos++)
		{
			if (buf[pos] == '\n' || (pos == read_len - 1 && pos != MAX_BUF_NOTTY))
			{
				if (buf[pos] == '\n' && iline)
				{
					shell.command_line[iline] = 0;
					pos++;
				}
				else if (!iline)
				{
					shell.command_line[0] = 0;
					pos += ++iline;
				}
				else
					shell.command_line[iline] = buf[pos];

				return (iline);
			}

			shell.command_line[iline++] =  buf[pos];
		}

		if (pos == MAX_BUF_NOTTY)
		{
			memset(buf, 0, read_len);
			pos = 0;
		}
	}

	return (false);
}
