#include "shell.h"

/**
 * main - Runs the shell
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	shell_t shell;
	(void) argc;

	shell.pName = argv[0];
	initialize(&shell);
	signal(SIGINT, handl_signint);
	repl(&shell);
	uninitialize(&shell);

	return (0);
}
