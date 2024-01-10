#include "main.h"
/**
 * handle_env - handles the built-in env command
 * Return: void
 */
void handle_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		char *ptr = *env;

		while (*ptr != '\0')
		{
			_putchar(*ptr);
			ptr++;
		}
	}
	_putchar('\n');
	env++;
}
