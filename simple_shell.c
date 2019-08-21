#include "shell.h"

/**
 * init - Construction function which calls the initializer function
 *
 * Descrption: This function has the constructor atribute
 * so C will always run it at first.
 */
void __attribute__((constructor)) init()
{
	/* We start the basic setup from our shell*/
	init_shell();
}

/**
 * init_shell - Initializes variables from shell
 */
void init_shell(void)
{
	/*isatty() 1 if the given file descriptor is a terminal, 0 otherwise.*/
	shell.tty = isatty(STDIN_FILENO);
	/*Run always true so it will be reading all the time*/
	shell.run = true;
}

/**
 * read_command - reads the command entered by the user
 * A: strlock to get the first token entered
 * B: strdup because strtok modifies the original string so we keep a copy
 * C: The first argument of owr shell will be the first token
 * Return: test
 */
int read_command(void)
{
	/* Contador de argumentos */
	int c = 0;

	if (_getline())/*if getline returns true*/
	{
		if (shell.command_line[0] != '\n')
		{
			shell.command = strtok(shell.command_line, " \n");/*A*/
			shell.command = _strdup(shell.command_line);/*B*/
			shell.argv[0] = shell.command;/*C*/
			if (_strcmp(shell.argv[0], "exit") == 0)/*if user types exit*/
			{
				free_args();
				exit(true);/*TODO: Pending exit status*/
			}
			if (_strcmp(shell.argv[0], "\n") == 0)/*if user types \n with no commands*/
				return (false);
			/*We save the rest of the arguments user entered*/
			for (c = 1; (shell.argv[c] = strtok(NULL, " \n")); c++)
				shell.argv[c] = _strdup(shell.argv[c]);
			shell.argv[c] = NULL;/*set the last element of the array to NULL*/
			return (true);
		}
	} else
	{
		shell.run = false;/*If _getline could not read*/
		return (false); /* EOF */
	}
	return (false);
}

/**
 * exec_command - Executes the full command
 * Return: @-1 if no commands entered
 */
int exec_command(void)
{
	int id, exec;

	if (read_command())/*if the command was read succesfully*/
	{
		id = fork();/**/

		if (!id)
		{
			exec = execve(shell.command, &shell.argv[0], NULL);
			if (exec == -1)
			{
				/*Print error if command doesn't exist*/
				error_printer(shell.argv[0], ": not found\n");
			}
			shell.run = false;/*To stop the child process*/
		} else
			wait(NULL);/*To sincronyse parent and child processes*/
	} else if (!shell.run && shell.tty)
	{
		_puts("\n");/*print \n if EOF and its a tty*/
		return (-1);/*if end of file return -1 so free wont execute*/
	} else
		return (-1);
	return (false);
}

/**
 * print_prompt_tty - checks if the given file descriptor is terminal
 * and prints the propmt if so.
 */
void print_prompt_tty(void)
{
	if (shell.tty)
		_puts("#cisfun$ ");
	fflush(stdout);
}
