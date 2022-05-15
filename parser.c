#include "shell.h"
#include "util.h"

/**
 * parse_command - splits a string into an array
 *
 * @shell: shell data
 * @command: commanf input
 * Return: 0 on success otherwise 1
 */
int parse_command(shell_t *shell, char *command)
{
	shell->argv = tokenize(command);

	return (execute(shell)); /* Success */
}
