#include "shell.h"
/**
 * exec - execute function with an without path
 * @path_bin: path dir
 * @cmd: command
 *
 * Return: Always 1 (Success)
*/
int exec(char *path_bin, char *cmd)
{
	char full_path[120] = {0};
	char *delim = "/";

	if (cmd[0] != delim[0] && path_bin)
	{
		strcat(full_path, path_bin);
		strcat(full_path, delim);
	}

	strcat(full_path, cmd);

	if (access(full_path, F_OK) == 0)
	{
		int id = fork();

		if (!id)
		{
			execve(full_path, &shell.argv[0], NULL);

			/* To stop the child process */
			shell.run = false;
		}
		else
		{
			wait(NULL); /* To sincronyse parent and child processes */
			return (true);
		}
	}

	return (false);
}
