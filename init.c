#include "shell.h"
#include "_string.h"

/**
 * initialize - setup shell variables
 *
 * @shell: shell data
 */
void initialize(shell_t *shell)
{
	unsigned int i;

	shell->argv = NULL;
	shell->command = NULL;

	for (i = 0; environ[i]; i++)
		;

	/* Make copy of the environs */
	shell->environ = malloc(sizeof(char *) * (i + 1));
	if (shell->environ == NULL)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return;
	}
	for (i = 0; environ[i]; i++)
		shell->environ[i] = _strdup(environ[i]);
	shell->environ[i] = NULL;
	shell->exitcode = 0;
	shell->countP = 1;
}

/**
 * uninitialize - frees shell data
 *
 * @shell: shell data
 */
void uninitialize(shell_t *shell)
{
	unsigned int i;

	for (i = 0; shell->environ[i]; i++)
		free(shell->environ[i]);
	free(shell->environ);
}
