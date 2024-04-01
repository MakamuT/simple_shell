#include "main.h"
/**
 * _strncmp - compares two strings up to n characters
 * @s1: first string
 * @s2: second string
 * @n: maximum number of characters to compare
 * Return: returns 0 if s1 and s2 are equal up to n characters,
 * -ve value if s1 < s2, +ve value if s1 > s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));
	}
	if (i == n)
		return (0);
	return ((int)(s1[i] - s2[i]));
}

/**
 * shell_cmd - parses through conditions for stdout
 * @argv: array of arguments
 * Return: 0 on success, -1 on error and updates errno
 */
int shell_cmd(char **argv)
{
	char *char_read = *argv;

	while (*argv)
	{
		if (argv[1] != NULL)
		{
			file_cmd(argv[1]);
			return (0);
		}
		if (char_read != NULL)
		{
			if (_strcmp(char_read, "exit") == 0)
				exec_exit(char_read);
			else if (_strcmp(char_read, "env") == 0)
				exec_env();
			else if (_strcmp(char_read, "getpid") == 0)
				p_pid();
			else if (_strncmp(char_read, "setenv", 6) == 0)
				exec_setenv(char_read);
			else if (_strncmp(char_read, "unsetenv", 8) == 0)
				exec_unsetenv(char_read);
			else if (_strncmp(char_read, "cd", 2) == 0)
				exec_cd(char_read);
			else if (_strncmp(char_read, "alias", 5) == 0)
				exec_alias(char_read);
			else
			{
				int hasScl = (_strchr(char_read, ';') != NULL);
				int hasAnd = (_strstr(char_read, "&&") != NULL);
				int hasOr = (_strstr(char_read, "||") != NULL);

				if (hasScl || hasAnd || hasOr)
					logical_ops(char_read);
				else
					execmd(char_read);
			}
		} free(char_read);
		argv++;
	} return (0);
}
