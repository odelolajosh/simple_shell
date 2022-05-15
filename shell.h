#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 1024
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/**
 * struct shell - shell data for current session
 *
 * @argv: argument vector
 * @command: input command
 * @environ: env variables
 */
typedef struct shell
{
	char **argv;
	char *command;
	char **environ;
} shell_t;

/**
 * struct token - Singly linked list for token
 *
 * @value: value of token
 * @next: pointer to next token
 */
typedef struct token
{
	char *value;
	struct token *next;
} token_t;

extern char **environ;

void initialize(shell_t *shell);
void uninitialize(shell_t *shell);
void handl_signint(int sig);
void repl(shell_t *shell);

char **tokenize(char *s);

char *_getenv(char **_environ, const char *name);
int _setenv(shell_t *shell, char *name, char *value, int overwrite);

int parse_command(shell_t *shell, char *command);
int execute(shell_t *shell);

void prompt(void);
char *read_line(int *chr);

#endif /* SHELL_H */
