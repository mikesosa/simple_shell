#include "shell.h"
/**
 * main - a while loop with all the necesary functions to run shell
 * Return: @false when the program ends whit no errors
 */
int main(void)
{
	while (shell.run)
	{
		/* We print promt only if it's a tty */
		print_prompt_tty();
		signal(SIGINT, signal_killer);/*2 Interrupt the process if Ctrl+C */
		if (exec_command() != -1)/*if EOF do not free()*/
			free_args();
	}
	/*Returns false if there is no erros*/
	return (false);
}
