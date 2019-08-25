#include "shell.h"
/**
 * main - a while loop with all the necesary functions to run shell
 *
 * Return: @false when the program ends whit no errors
 */
int main(void)
{
	/* We create structure that will use the entire program */
	shell_t shell;

	/* 2 Interrupt the process if Ctrl+C */
	signal(SIGINT, signal_killer);

	/* Fill in some fields of the structure */
	init_shell(&shell);

	while (shell.run)
	{

		/* We print promt only if it's a tty */
		print_prompt_tty(&shell);

		/* If EOF do not free() */
		if (exec_command(&shell) != -1)
			free_args(&shell);
	}

	/* Returns false if there is no errors */
	return (false);
}
