#include "shell.h"
/**
 * builtin_exit - exit of the shell
 * @shell: global shell struct
 *
 * Return: void
 */
void builtin_exit(void *shell)
{
	shell_t *shell_tmp = (shell_t *)shell;
	char **argv = shell_tmp->argv;

	/* Exit of the shell with error */
	shell_tmp->exit_code = argv[1] ? atoi(argv[1]) : 0;
	shell_tmp->run = 0;
}
/**
 * builtin_cd - change working directory
 * @shell: global shell struct
 *
 * Return: void
 */
void builtin_cd(void *shell)
{
	shell_t *shell_tmp = (shell_t *) shell;
	static char old_path[120] = {0};
	char **argv = shell_tmp->argv;
	char path[120] = {0};

	/* Copy the path that the user sent */
	if (argv[1])
		_strcpy(path, argv[1]);

	if (!argv[1] || argv[1][0] == '~')
	{
		_strcpy(path, _getenv("HOME"));

		if (argv[1])
			_strcat(path, &argv[1][1]);
	}
	else if (argv[1][0] == '-')
	{
		if (old_path[0])
			_strcpy(path, old_path);
		else
			getcwd(path, sizeof(path));
	}

	getcwd(old_path, sizeof(old_path));
	chdir(path);
}
/**
 * is_builtin - search builtin command
 * @shell: global shell struct
 *
 * Return: Always 1 (Success)
 */
int is_builtin(shell_t *shell)
{
	int i;

	for (i = 0; shell->builtin_list[i].name; i++)
	{
		if (!_strcmp(shell->builtin_list[i].name, shell->command))
		{
			shell->builtin_fun = shell->builtin_list[i].function;
			return (true);
		}
	}

	return (false);
}
