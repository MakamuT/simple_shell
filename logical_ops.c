#include "main.h"
#define MAX_ARGS 256
/**
 * _strstr - locates a substring in a string
 * @haystack: the string to search in
 * @needle: the substring to find
 * Return: pointer to the first occurrence of the substring
 * or NULL if the substring is not found
 */
char *_strstr(const char *haystack, const char *needle)
{
	int i, j = 0;

	while (needle[j] != '\0')
		j++;
	while (*haystack)
	{
		for (i = 0; needle[i]; i++)
		{
			if (haystack[i] != needle[i])
				break;
		}
		if (i != j)
			haystack++;
		else
			return ((char *)haystack);
	}
	return (NULL);
}

/**
 * logical_ops - handles each command separated by logical operators
 * @args: user input
 */
void logical_ops(char *args)
{
	char *token;
	int status;
	pid_t pid = fork();
	char *arg[MAX_ARGS];

	token = _strtok(args, " \t\n");
	while (token != NULL)
	{
		if (pid == -1)
			perror("fork");
		if (pid == 0)
		{
			arg[0] = token;
			arg[1] = NULL;
			execve(arg[0], arg, NULL);
			perror("execve");
		} else
		{
			waitpid(pid, &status, 0);
			if (_strstr(args, "&&") != NULL)
			{
				if (status != 0)
					break;
			} else if (_strstr(args, "||") != NULL)
			{
				if (status == 0)
					break;
			}
			token = _strtok(NULL, " \t\n");
		}
	}
}
