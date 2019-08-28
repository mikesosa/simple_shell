#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: string (char *)
 * @src: string (char *)
 *
 * Return: char *
 */
char *_strcat(char *dest, const char *src)
{
	const char *t_src = src;
	char *t_dest = dest;

	while (*dest++)
		;
	dest--;

	while (*src)
		*dest++ = *src++;

	dest = t_dest;
	src = t_src;

	return (t_dest);
}
/**
 * exec - execute function with an without path
 * @shell: global struct shell
 * @path_bin: path dir
 * @cmd: command
 *
 * Return: Always 1 (Success)
*/
int exec(shell_t *shell, char *path_bin, char *cmd)
{
	char full_path[120] = {0};
	const char *delim = "/";
	int status = 0;

	if (cmd[0] != delim[0] && path_bin)
	{
		_strcat(full_path, path_bin);
		_strcat(full_path, delim);
	}

	_strcat(full_path, cmd);

	if (access(full_path, F_OK) == 0)
	{
		free(shell->command);
		shell->command = _strdup(full_path);
		int id = fork();

		if (!id)
		{
			execve(shell->command, &shell->argv[0], NULL);

			/* To stop the child process */
			shell->run = false;
		}
		else
		{
			wait(&status); /* To sincronyse parent and child processes */


			if (WIFEXITED(status))
			{
				shell->exit_code_child = WEXITSTATUS(status);
			}

			return (true);
		}
	}

	return (false);
}
