#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h> /*to handle Ctrl + C*/

/* Functions for simple_shell*/
void __attribute__((constructor)) init();
void print_prompt_tty(void);
int exec_command(void);/*I had to change the return value to free argv*/
int read_command(void);
void init_shell(void);
void error_printer(char *command, char *to_print);
void free_args(void);
void signal_killer(int n);/*Takes signal CTRL+C*/

/* Functions for getting strings*/
int _getline(void);
int _strlen(char *s);
char *_strdup(char *s);
void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);

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
	char run;
	char tty;
} shell_t;

shell_t shell;

#endif
