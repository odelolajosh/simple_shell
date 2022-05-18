#include "shell.h"
#include "_string.h"
#include <string.h>
#include "util.h"


/**
 * env_cmp - compares a name with env key
 *
 * @envvar: env variable
 * @name: name to compare
 *
 * Return: 0 if not match else an integer
 */
int env_cmp(const char *envvar, const char *name)
{
	unsigned int i;

	for (i = 0; envvar[i] != '='; i++)
		if (envvar[i] != name[i])
			return (0);

	return (++i);
}

/**
 * _getenv - Gets the value of an environment variable
 *
 * @_environ: env variables
 * @name: given name
 * Return: the env variable if found otherwise NULL
 */
char *_getenv(char **_environ, const char *name)
{
	unsigned int i;
	int offset;

	for (i = 0; _environ[i]; i++)
	{
		offset = env_cmp(_environ[i], name);
		if (offset)
			return (_environ[i] + offset);
	}

	return (NULL);
}

/**
 * makeenv - create an environment variable
 *
 * @var: variable name
 * @val: variable value
 * Return: the env variable if found otherwise NULL
 */
char *makeenv(char *var, char *val)
{
	size_t len_var, len_val;
	char *env;

	len_var = _strlen(var);
	len_val = _strlen(val);
	env = malloc(sizeof(char) * (len_val + len_var + 2));
	if (!env)
		return (NULL);
	_strcpy(env, var);
	_strcat(env, "=");
	_strcat(env, val);
	_strcat(env, "\0");

	return (env);
}

/**
 * _setenv - change or add an environment variable
 *
 * @shell: shell data
 * @name: variable name
 * @value: variable value
 * @overwrite: 0 to avoid change otherwise any other integer
 * Return: the env variable if found otherwise NULL
 */
int _setenv(shell_t *shell, char *name, char *value, int overwrite)
{
	unsigned int i;
	char *envv, *var_env, *backup, *newenv;

	for (i = 0; shell->environ[i]; i++)
	{
		envv = _strdup(shell->environ[i]);
		var_env = strtok(envv, "=");
		if (_strcmp(var_env, name) == 0)
		{
			if (overwrite == 0)
				return (0);
			backup = _strdup(shell->environ[i]);
			free(shell->environ[i]);
			newenv = makeenv(name, value);
			if (!newenv)
			{
				free(envv);
				shell->environ[i] = backup;
				return (-1); /* TODO => Set errno */
			}
			shell->environ[i] = newenv;
			free(envv);
			free(backup);
			return (0);
		}
		free(envv);
	}

	shell->environ = _realloc2(shell->environ, i, sizeof(char *) * (i + 2));
	shell->environ[i] = makeenv(name, value);
	shell->environ[i + 1] = NULL;

	return (0);
}

/**
 * hsh_env - prints env variables
 *
 * @shell: shell data
 * Return: 0 for success otherwise another integer
 */
int hsh_env(shell_t *shell)
{
	int i = 0;
	(void) shell;

	/* Todo -> print envs */
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
