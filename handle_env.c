#include "main.h"
/**
 * handle_env - handles the built-in env command
 * Return: void
 */
void handle_env(void)
{
	extern char **environ;
	for (char **env = environ; *env; env++)
		_putchar(*env);
	_putchar('\n');
}
