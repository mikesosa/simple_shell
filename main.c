#include "shell.h"
/**
 * main - a while loop with all the necesary functions to run shell
 * @argc: arguments count
 * @argv: arguments vector
 * @env: environ
 *
 * Return: @false when the program ends whit no errors
 */
int main(void)
{
	while (shell.run)
	{
		/* 2 Interrupt the process if Ctrl+C */
		signal(SIGINT, signal_killer);

		/* We print promt only if it's a tty */
		print_prompt_tty();

		/* If EOF do not free() */
		if (exec_command() != -1)
			free_args();
	}

	/* Returns false if there is no errors */
	return (false);
}
