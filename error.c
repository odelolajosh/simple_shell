#include "shell.h"
#include "_string.h"

/**
 * error_message - displays error message to terminal
 *
 * @shell: the command
 */
void error_message(shell_t *shell)
{
	int len = _strlen(shell->name), len2, len3;
	char *count;

	count = _itoa(shell->count);
	len2 = _strlen(count);
	len3 = _strlen(shell->argv[0]);

	write(STDERR_FILENO, shell->name, len);
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, count, len2);
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, shell->argv[0], len3);
	write(STDERR_FILENO, ": not found\n", 13);

	free(count);
}
