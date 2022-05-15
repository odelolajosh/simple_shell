#include "shell.h"

/**
 * repl - Read-Eval-Print-Loop for the shell
 *
 * @shell: shell data
 */
void repl(shell_t *shell)
{
	char *cmd;
	int chr;

	do {
		prompt();

		cmd = read_line(&chr);
		if (chr == -1)
		{
			free(cmd);
			write(STDOUT_FILENO, "\n", 2);
			exit(EXIT_SUCCESS);
		}

		if (cmd == NULL)
			continue;

		parse_command(shell, cmd);
		
		free(cmd);
	} while (1);
}
