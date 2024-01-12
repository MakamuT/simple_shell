#include "main.h"
/**
 * prompt - command line interpreter
 * @argc: int
 * @argv: char
 * Return: 0
 */

int prompt(int argc, char **argv)
{
	char *prompt = "simple_shell$ ";
	char *lineptr;
	size_t n = 0;
	(void)argc;
	(void)argv;

	while (*prompt != '\0')
	{
		_putchar(*prompt);
		prompt++;
	}
	_getline(&lineptr, &n, stdin);

	while (*lineptr != '\0')
	{
		_putchar(*lineptr);
		lineptr++;
	}
	_putchar ('\n');

	free(lineptr);
	return (0);
}
