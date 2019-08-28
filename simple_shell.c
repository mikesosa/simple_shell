#include "shell.h"

/**
 * init_shell - Initializes variables from shell
 * @shell: global struct shell
 * @builtin_list: list of the builtin commands
 * @argv: argv of the main function
 *
 * Return: void
 */
shell_t *init_shell(shell_t *shell, b_command *builtin_list, char **argv)
{
	int i = 0;

	/* isatty() 1 if the given file descriptor is a terminal, 0 otherwise */
	shell->tty = (isatty(STDIN_FILENO) && !argv[1]);
	shell->tty += (isatty(STDOUT_FILENO) ? 2 : 0);
	errno = 0; /* Flush extern errno variable */

	shell->builtin_list = builtin_list;
	shell->path = _getenv("PATH");
	shell->count_commands = 0;
	shell->name = argv[0] + 2;
	shell->main_argv = argv;
	shell->exit_code = 0;
	shell->exit_code_child = 0;
	shell->exit = 0;

	_memset(shell->buf_itoa, 0, sizeof(shell->buf_itoa));
	shell->path = _strdup(shell->path);

	shell->path_dirs[0] = _strtok(shell->path, ":\n");

	if (shell->path && shell->path_dirs[0])
	{
		for (i = 1; (shell->path_dirs[i] = _strtok(NULL, ":\n")); i++)
			;
	}

	/* Set the guardian to stop the loop */
	shell->path_dirs[i] = NULL;

	/* Run always true so it will be reading all the time */
	shell->run = true;

	return (shell);
}
/**
 * read_command - reads the command entered by the user
 * @shell: global struct shell
 * A: strlock to get the first token entered
 * B: strdup because _strtok modifies the original string so we keep a copy
 * C: The first argument of owr shell will be the first token
 *
 * Return: return 1 if there is a new line digit
 */
int read_command(shell_t *shell)
{
	int c = 0, r = 0;

	shell->count_commands++;
	if (shell->tty & 1 && !shell->main_argv[1])
		r = _readline(shell);
	else
		r = _getline(shell);
	if (r)
	{
		if (shell->command_line[0] != '\n')
		{
			shell->command = _strtok(shell->command_line, " \n"); /* A */
			shell->command = _strdup(shell->command_line); /* B */
			shell->argv[0] = shell->command; /* C */
			if (_strcmp(shell->argv[0], "\n") == 0)
				return (false);
			if (shell->command[0] == '#')
			{
				shell->argv[1] = NULL;
				return (false);
			}
			for (c = 1; (shell->argv[c] = _strtok(NULL, " \n")); c++)
			{
				if (shell->argv[c][0] == '#')
				{
					shell->argv[c] = NULL;
					break;
				}
				shell->argv[c] = _strdup(shell->argv[c]);
			}
			variables(shell);
			shell->argv[c] = NULL;/* Set the last element of the array to NULL */
			return (true);
		}
	}
	else
		shell->run = false; /* If _getline could not read */
	return (false);
}
/**
 * exec_command - Executes the full command
 * @shell: global struct shell
 *
 * Return: @-1 if no commands entered
 */
int exec_command(shell_t *shell)
{
	int i, r = 0, builtin = 0;

	/* If the command was read succesfully */
	if (read_command(shell) && shell->command_line[0])
	{
		builtin = is_builtin(shell);

		if (builtin)
			shell->builtin_fun(shell);
		else if (shell->argv[0][0] == '.' && shell->argv[0][1] == '/')
			r = exec(shell, NULL, shell->command_line);
		else if (!shell->path_dirs[0] || shell->path[0] == ':')
			r = exec(shell, NULL, shell->command_line);
		else
		{
			for (i = 0; shell->path_dirs[i] && !r; i++)
				r = exec(shell, shell->path_dirs[i], shell->command_line);
		}

		if (!r && errno)
		{
			shell->exit_code_child = 127;
			_perror(shell);
		}
	}
	else if (!shell->run && (shell->tty == 3))
	{
		/* Print \n if EOF and its a tty */
		_puts("\n");

		/* If end of file return -1 so free wont execute */
		return (-1);
	}
	else
		return ((shell->tty == 3) ? -2 : -1); /* If the user gives a single enter */

	return (false);
}
/**
 * print_prompt_tty - checks if the given file descriptor is terminal
 * and prints the propmt if so
 * @shell: global struct shell
 *
 * Return: void
 */
void print_prompt_tty(shell_t *shell)
{
	if (!shell || (shell && (shell->tty == 3)))
		_puts("\x1B[1;33m#shellyta$\x1B[0m "); /*Prints the promt in color*/

	fflush(stdout);
}
