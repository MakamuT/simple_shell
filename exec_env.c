#include "main.h"
/**
 * exec_env - handles the built-in env command
 * Return: void
 */
void exec_env(void)
{
	char **env = environ;
	char *ptr;

	while (*env != NULL)
	{
		ptr = *env;
		while (*ptr != '\0')
		{
			_putchar(*ptr);
			ptr++;
		}
		_putchar('\n');
		env++;
	}
}
