#include "shell.h"

/**
 * main - Runs the shell
 *
 * Return: 0
 */
int main(void)
{
	signal(SIGINT, handl_signint);
	repl();

	return (0);
}
