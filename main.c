#include "shell.h"

/**
 * main - a while loop with all the necesary functions to run shell
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: @false when the program ends whit no errors
 */
int main(__attribute((unused))int argc, char *argv[])
{
	/* Builtin functions */
	b_command builtin_list[] = {
		{builtin_history, "history"},
		{builtin_exit, "exit"},
		{builtin_env, "env"},
		{builtin_cd, "cd"},
		{NULL, NULL}
	};

	/* We create structure that will use the entire program */
	shell_t shell;

	/* 2 Interrupt the process if Ctrl+C */
	signal(SIGINT, signal_killer);

	/* Fill in some fields of the structure */
	init_shell(&shell, builtin_list, argv);

	while (shell.run) /* This loop keeps the shell running */
	{

		/* We print promt only if it's a tty */
		print_prompt_tty(&shell);

		/* If EOF do not free() */
		if (exec_command(&shell) != -1)
			free_args(&shell);
	}

	/* Free own path */
	free(shell.path);

	/* Returns false if there is no errors */
	if (shell.exit && shell.argv[1])
		return (shell.exit_code);

	return (shell.exit_code_child);
}
