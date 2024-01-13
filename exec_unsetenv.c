#include "main.h"
/**
 * exec_unsetenv - Removes an environment variable
 * @args: array of arguments
 * Return: void
 */
void exec_unsetenv(char *args)
{
	char *arg[2];
	char *token = _strtok(args, " ");
	int i = 0;

	while (token != NULL)
	{
		arg[i++] = token;
		token = _strtok(NULL, " ");
	}
	if (i == 2)
	{
		if (unsetenv(arg[1]) != 0)
			perror("unsetenv");
	}
	else
		printf("Error: unsetenv VARIABLE\n");
}
