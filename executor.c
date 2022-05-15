#include "shell.h"
#include "util.h"
#include "_string.h"
#include <string.h>

/**
 * _which - find the file for a command
 *
 * @_environ: env variables
 * @command: command input
 * Return: 0 on failure otherwise 1
 */
char *_which(char **_environ, char *command)
{
	char *path, *path_dup, *spath, *file;
	int len_spath, len_cmd;
	struct stat st;

	path = _getenv(_environ, "PATH");
	if (!path)
		return (NULL);

	path_dup = _strdup(path);
	len_cmd = _strlen(command);
	spath = strtok(path_dup, ":");
	while (spath != NULL)
	{
		len_spath = _strlen(spath);
		file = malloc(sizeof(char) * (len_spath + len_cmd + 2));
		if (!file)
		{
			write(STDERR_FILENO, ": allocation error\n", 18);
			exit(EXIT_FAILURE);
		}
		_strcpy(file, spath);
		_strcat(file, "/");
		_strcat(file, command);
		_strcat(file, "\0");
		if (stat(file, &st) == 0)
		{
			free(path_dup);
			return (file);
		}
		free(file);
		spath = strtok(NULL, ":");
	}
	free(path_dup);

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
			return (command);
	}
	return (NULL);
}

/**
 * execute - executes a command
 *
 * @shell: shell data
 * Return: 0 on success otherwise 1
 */
int execute(shell_t *shell)
{
	pid_t pid;
	int sys;
	char *file;

	/* Todo ->  Check if executable */
	file = _which(shell->environ, shell->argv[0]);
	if (!file)
	{
		write(STDERR_FILENO, "Not an executable\n", 19);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(file, shell->argv, shell->environ);
	}
	else if (pid < 0)
	{
		perror(shell->argv[0]);
		return (1);
	}
	else
	{
		wait(&sys);
	}

	return (1);
}
