#include "main.h"
/**
 * prompt - command line interpreter
 * Return: void
 */

void prompt(void)
{
	char *prompt = "simple_shell$ ";

	while (*prompt != '\0')
	{
		_putchar(*prompt);
		prompt++;
	}
	fflush(stdout);
}
