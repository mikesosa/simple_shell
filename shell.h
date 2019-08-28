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
#include <errno.h>

#define MAX_BUF_NOTTY 4096
#define MAX_LEN 4096
#define false 0
#define true 1

/* Prototype builtin functions */
typedef void (*fun)(void *);

/**
 * struct b_command - struct of a builtin command
 * @function: callback function
 * @name: builtin command
 *
 * Description: Necessary variables needed to a builtin command
 */
typedef struct b_command
{
	fun function;
	const char *name;
} b_command;

/**
 * struct shell_t - Necessary variables needed to simple_shell
 * @command_line: bufer where we strore the _getline, of MAX_LEN size.
 * @path_dirs: array of dirs
 * @exit_code_child: exit code child
 * @count_commands: count commands
 * @buf_itoa: buffer integer to string
 * @name: program name
 * @main_argv: args vector
 * @command_len: lenght of the string entered by the user
 * @argv: Don't know
 * @exit_code: code return exit
 * @command: Don't know
 * @path: Don't know
 * @run: Run always true since our main loop will always be reading
 * @tty: teletype tell us if the given file descriptor is a terminal
 * @builtin_list: list of the builtin commands
 * @builtin_fun: callback function
 * @exit: when its an exit for builtin
 *
 * Description: Necessary variables needed to simple_shell
 * for Holberton project
 */
typedef struct shell_t
{
	char command_line[MAX_LEN];
	char *path_dirs[512];
	int exit_code_child;
	int count_commands;
	char buf_itoa[64];
	const char *name;
	char **main_argv;
	int command_len;
	char *argv[512];
	char exit_code;
	char *command;
	char *path;
	char run;
	char tty;
	int exit;

	/* buitin */
	b_command *builtin_list;
	fun builtin_fun;
} shell_t;

/* Functions for simple_shell*/
shell_t *init_shell(shell_t *, b_command *, char **);
void __attribute__((constructor)) init();
int exec(shell_t *, char *, char *);
void error_printer(char *, char *);
void *_memset(void *, int, size_t);
void print_prompt_tty(shell_t *);
void _perror(shell_t *shell);
void _pexit(shell_t *shell);
int exec_command(shell_t *);
char *_getenv(const char *);
int read_command(shell_t *);
void free_args(shell_t *);
void signal_killer(int);
int itoa(int, char *);

void builtin_history(void *shell);
int is_builtin(shell_t *shell);
void builtin_exit(void *shell);
void builtin_env(void *shell);
void builtin_cd(void *shell);

/* Variables */
void variables(shell_t *shell);

/* Functions for getting strings*/
int _strcmp(const char *s1, const char *);
size_t _strcspn(char *, const char *);
size_t _strspn(char *, const char *);
char *_strtok(char *, const char *);
char *_strcat(char *, const char *);
void _puts(const char *);
int _readline(shell_t *);
int _getline(shell_t *);
char *_strdup(char *);
int _strlen(char *);
int _putchar(char);
int string_to_int(char *s);


/* For deleting blank spaces */
char *_strcpy(char *, char *);
void deblank(shell_t *);

#endif
