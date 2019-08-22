#include "shell.h"

/**
 * init - Construction function which calls the initializer function
 *
 * Descrption: This function has the constructor atribute
 * so C will always run it at first.
 *
 * Return: void
 */
void __attribute__((constructor)) init()
{
	/* We start the basic setup from our shell */
	init_shell();
}

/**
 * init_shell - Initializes variables from shell
 *
 * Return: void
 */
void init_shell(void)
{
	/* isatty() 1 if the given file descriptor is a terminal, 0 otherwise */
	shell.tty = isatty(STDIN_FILENO);

	/* Run always true so it will be reading all the time */
	shell.run = true;
}

/**
 * read_command - reads the command entered by the user
 * A: strlock to get the first token entered
 * B: strdup because strtok modifies the original string so we keep a copy
 * C: The first argument of owr shell will be the first token
 *
 * Return: return 1 if there is a new line digit
 */
int read_command(void)
{
	int c = 0, r = 0;

	/* If getline returns true */
	if (shell.tty)
		r = _readline();
	else
		r = _getline();

	if (r)
	{
		if (shell.command_line[0] != '\n')
		{
			shell.command = _strtok(shell.command_line, " \n"); /* A */
			shell.command = _strdup(shell.command_line); /* B */
			shell.argv[0] = shell.command; /* C */

			/* If user types exit */
			if (_strcmp(shell.argv[0], "exit") == 0)
			{
				free_args();
				exit(true);
			}

			/* If user types \n with no commands */
			if (_strcmp(shell.argv[0], "\n") == 0)
				return (false);

			/* We save the rest of the arguments user entered */
			for (c = 1; (shell.argv[c] = _strtok(NULL, " \n")); c++)
				shell.argv[c] = _strdup(shell.argv[c]);

			/* Set the last element of the array to NULL */
			shell.argv[c] = NULL;
			return (true);
		}
	}
	else
		shell.run = false; /* If _getline could not read */

	return (false);
}

/**
 * exec_command - Executes the full command
 *
 * Return: @-1 if no commands entered
 */
int exec_command(void)
{
	int id;

	/* If the command was read succesfully */
	if (read_command())
	{
		id = fork();

		if (!id)
		{
			execve(shell.command, &shell.argv[0], NULL);
			/* Print error if command doesn't exist */
			perror(shell.command);

			/* To stop the child process */
			shell.run = false;
		}
		else
			wait(NULL); /* To sincronyse parent and child processes */
	}
	else if (!shell.run && shell.tty)
	{
		/* Print \n if EOF and its a tty */
		_puts("\n");

		/* If end of file return -1 so free wont execute */
		return (-1);
	}
	else
		return (-1); /* If the user gives a single enter */

	return (false);
}

/**
 * print_prompt_tty - checks if the given file descriptor is terminal
 * and prints the propmt if so
 *
 * Return: void
 */
void print_prompt_tty(void)
{
	if (shell.tty)
		_puts("#cisfun$ ");

	fflush(stdout);
}
