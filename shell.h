#ifndef SHELL_H
#define SHELL_H

#include <signal.h> /* To handle Ctrl + C */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Functions for simple_shell*/
int exec_command(void); /* I had to change the return value to free argv */
void signal_killer(int n); /* Takes signal CTRL+C */
void error_printer(char *command, char *to_print);
void __attribute__((constructor)) init();
void print_prompt_tty(void);
int read_command(void);
void init_shell(void);
void free_args(void);

/* Functions for getting strings*/
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
void _puts(char *str);
int _strlen(char *s);
int _putchar(char c);
int _getline(void);

/**
 * MAX_LEN - Max size of buffer
 */

#define MAX_LEN 1024
#define false 0
#define true 1

/**
 * struct shell_t - Necessary variables needed to simple_shell
 * @command_line: bufer where we strore the _getline, of MAX_LEN size.
 * @command_len: lenght of the string entered by the user
 * @argv: Don't know
 * @command: Don't know
 * @run: Run always true since our main loop will always be reading
 * @tty: teletype tell us if the given file descriptor is a terminal
 *
 * Description: Necessary variables needed to simple_shell
 * for Holberton project
 */
typedef struct shell_t
{
	char command_line[MAX_LEN];
	int command_len;
	char *argv[512];
	char *command;
	char **env;
	char run;
	char tty;
} shell_t;

shell_t shell;

#endif
