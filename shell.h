#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF_NOTTY 4096
#define MAX_LEN 1024
#define false 0
#define true 1

/**
 * struct shell_t - Necessary variables needed to simple_shell
 * @command_line: bufer where we strore the _getline, of MAX_LEN size.
 * @path_dirs: array of dirs
 * @command_len: lenght of the string entered by the user
 * @argv: Don't know
 * @command: Don't know
 * @path: Don't know
 * @run: Run always true since our main loop will always be reading
 * @tty: teletype tell us if the given file descriptor is a terminal
 *
 * Description: Necessary variables needed to simple_shell
 * for Holberton project
 */
typedef struct shell_t
{
	char command_line[MAX_LEN];
	char *path_dirs[512];
	int command_len;
	char *argv[512];
	char *command;
	char *path;
	char run;
	char tty;
} shell_t;

/* Functions for simple_shell*/
void __attribute__((constructor)) init();
int exec(shell_t *, char *, char *);
void error_printer(char *, char *);
void *_memset(void *, int, size_t);
void print_prompt_tty(shell_t *);
shell_t *init_shell(shell_t *);
int exec_command(shell_t *);
char *_getenv(const char *);
int read_command(shell_t *);
void free_args(shell_t *);
void signal_killer(int);

/* Functions for getting strings*/
int _strcmp(const char *s1, const char *);
size_t _strcspn(char *, const char *);
size_t _strspn(char *, const char *);
char *_strtok(char *, const char *);
char *_strcat(char *, const char *);
void _puts(const char *);
char *_strdup(char *);
int _strlen(char *);
int _putchar(char);
int _readline(shell_t *);
int _getline(shell_t *);

/* For deleting blank spaces */
char *_strcpy(char *, char *);
void deblank(shell_t *);

#endif
