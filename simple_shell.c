#include "shell.h"
/**
 * init_shell - Initializes variables from shell
 * @shell: global struct shell
 *
 * Return: void
 */
shell_t *init_shell(shell_t *shell)
{
	/* isatty() 1 if the given file descriptor is a terminal, 0 otherwise */
	shell->tty = isatty(STDIN_FILENO);
	int i = 0;

	shell->path = _getenv("PATH");

	if (shell->path && strtok(shell->path, ":\n"))
	{
		while ((shell->path_dirs[i] = strtok(NULL, ":\n")))
			i++;
	}

	shell->path_dirs[i] = NULL;

	/* Run always true so it will be reading all the time */
	shell->run = true;

	return (shell);
}
/**
 * read_command - reads the command entered by the user
 * @shell: global struct shell
 * A: strlock to get the first token entered
 * B: strdup because strtok modifies the original string so we keep a copy
 * C: The first argument of owr shell will be the first token
 *
 * Return: return 1 if there is a new line digit
 */
int read_command(shell_t *shell)
{
	int c = 0, r = 0;

	/* If getline returns true */
	if (shell->tty)
		r = _readline(shell);
	else
		r = _getline(shell);

	if (r)
	{
		if (shell->command_line[0] != '\n')
		{
			shell->command = strtok(shell->command_line, " \n"); /* A */
			shell->command = _strdup(shell->command_line); /* B */
			shell->argv[0] = shell->command; /* C */

			/* If user types \n with no commands */
			if (_strcmp(shell->argv[0], "\n") == 0)
				return (false);

			/* We save the rest of the arguments user entered */
			for (c = 1; (shell->argv[c] = strtok(NULL, " \n")); c++)
				shell->argv[c] = _strdup(shell->argv[c]);

			/* Set the last element of the array to NULL */
			shell->argv[c] = NULL;
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
	int i, r = 0;

	/* If the command was read succesfully */
	if (read_command(shell) && shell->command_line[0])
	{
		if (!shell->path_dirs[0] || shell->path[0] == ':')
			r = exec(shell, NULL, shell->command_line);
		else
		{
			for (i = 0; shell->path_dirs[i] && !r; i++)
				r = exec(shell, shell->path_dirs[i], shell->command_line);
		}

		if (!r)
			/* Print error if command doesn't exist */
			perror(shell->command);
	}
	else if (!shell->run && shell->tty)
	{
		/* Print \n if EOF and its a tty */
		_puts("\n");

		/* If end of file return -1 so free wont execute */
		return (-1);
	}
	else
		return (shell->tty ? -2 : -1); /* If the user gives a single enter */

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
	if (!shell || (shell && shell->tty))
		_puts("#cisfun$ ");

	fflush(stdout);
}
