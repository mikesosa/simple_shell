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

/* Functions for simple_shell*/
void error_printer(char *command, char *to_print);
void __attribute__((constructor)) init();
void *_memset(void *s, int c, size_t n);
int exec(char *path, char *command);
char *_getenv(const char *name);
void print_prompt_tty(void);
void signal_killer(int n);
int exec_command(void);
int read_command(void);
void init_shell(void);
void free_args(void);

/* Functions for getting strings*/
size_t _strcspn(char *s, const char *reject);
size_t _strspn(char *s, const char *accept);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
void _puts(const char *str);
char *_strdup(char *s);
int _strlen(char *s);
int _putchar(char c);
int _readline(void);
int _getline(void);

/* For deleting blank spaces */
char *_strcpy(char *dest, char *src);
void deblank(void);

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

shell_t shell;

#endif
