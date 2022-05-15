#include "shell.h"
#include "util.h"

/**
 * parse_command - splits a string into an array
 *
 * @shell: shell data
 * @command: command input
 * Return: 0 on success otherwise 1
 */
int parse_command(shell_t *shell, char *command)
{
	int flag;

	shell->command = command;
	shell->argv = tokenize(command);

	flag = execute(shell);
	free(shell->argv);

	return (flag); /* Success */
}
