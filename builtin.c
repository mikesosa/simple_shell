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
	int j = 0, len_argv = 0;
	unsigned long int x = 0;

	len_argv = _strlen(argv[1]);/*len of argv[1]*/
	if (argv[1] == '\0') /*if no arguments*/
		exit(0);
	while (argv[1][j] != '\0') /*Filter is it is a number*/
	{
		if (!(argv[1][j] >= '0' && argv[1][j] <= '9'))
		{
			_pexit(shell);
			exit(2);
		}
		j++;
	}
	if (len_argv <= 10) /*if not too long*/
	{
		x = string_to_int(argv[1]);
		if (x > 2147483647)
		{
			_pexit(shell);
			exit(2);
		}
		shell_tmp->exit_code = argv[1] ? atoi(argv[1]) : 0;
		exit(shell_tmp->exit_code); /* Exit of the shell with error */
	} else
	{
		_pexit(shell);
		exit(2);
	}
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
	char *tmp = NULL;

	/* Copy the path that the user sent */
	if (argv[1])
		_strcpy(path, argv[1]);

	if (!argv[1] || argv[1][0] == '~')
	{
		tmp = _getenv("HOME");

		if (tmp)
		{
			_strcpy(path, tmp);

			if (argv[1])
				_strcat(path, &argv[1][1]);
		}
		else
			return;
	}
	else if (argv[1][0] == '-')
	{
		if (old_path[0])
			_strcpy(path, old_path);
		else
			getcwd(path, sizeof(path));
	}

	getcwd(old_path, sizeof(old_path));

	if (!chdir(path))
		errno = 0;
}
/**
 * builtin_env - print enviroment
 * @shell: global shell struct
 *
 * Return: void
 */
void builtin_env(__attribute((unused))void *shell)
{
	int i;

	for (i = 0; __environ[i]; i++)
	{
		_puts(__environ[i]);
		_putchar('\n');
	}
	errno = 0;
}
/**
 * builtin_history - print history of commans
 * @shell: global shell struct
 *
 * Return: void
 */
void builtin_history(__attribute((unused))void *shell)
{
	;
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
	errno = 0;

	return (false);
}
