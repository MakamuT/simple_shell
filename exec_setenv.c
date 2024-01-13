#include "main.h"
/**
 * _strlen - returns the length of a String
 * @s: String to be checked
 * Return: length of the String
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * exec_setenv - Initializes a new environment variable,
 * or modifies an existing one
 * @args: array of arguments
 * Return: void
 */
void exec_setenv(char *args)
{
	char *arg[3];
	char *token = _strtok(args, " ");
	int i = 0;

	while (token != NULL)
	{
		arg[i++] = token;
		token = _strtok(NULL, " ");
	}
	if (i == 3)
	{
		if (setenv(arg[1], arg[2], 1) != 0)
			perror("setenv");
	}
	else
		printf("Error: setenv VARIABLE VALUE\n");
}
