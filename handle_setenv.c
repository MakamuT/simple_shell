#include "main.h"
/**
 * _strlen - returns the length of a String
 * @s: String to be checked
 * Return: length of the String
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * handle_setenv - Initializes a new environment variable,
 * or modifies an existing one
 * @args: array of arguments
 * Return: void
 */
void handle_setenv(char **args)
{
	char *err = "Usage: setenv Variable VALUE\n";
	int len = _strlen(err);

	if (args[1] == NULL || args[2] == NULL)
		write(STDERR_FILENO, err, len);
	if (setenv(args[1], args[2], 1) != 0)
		perror("setenv error");
}
