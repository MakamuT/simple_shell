#include "main.h"
/**
 * _getenv - obtains the current value of the environment variable name
 * @name: environment variable name
 * Return: pointer to the requested value, or NULL if not found
 */
char *_getenv(const char *name)
{
	size_t len = _strlen(name);
	char **env;

	if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL)
		return (NULL);
	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
			return (&((*env)[len + 1]));
	}
	return (NULL);
}

/**
 * exec_cd - Changes the current directory of the process
 * @dir: directory
 * Return: void
 */
void exec_cd(char *dir)
{
	char *args[3];
	char *token = _strtok(dir, " ");
	int i = 0;

	while (token != NULL && i < 3)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	if (i == 1)
	{
		if (chdir(_getenv("HOME")) != 0)
			perror("chdir");
	} else if (i == 2)
	{
		if (chdir(args[1]) != 0)
			perror("chdir");
	} else
		printf("Usage: cd [DIRECTORY]\n");
}
