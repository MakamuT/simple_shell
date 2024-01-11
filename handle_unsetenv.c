#include "main.h"
/**
 * handle_unsetenv - Removes an environment variable
 * @args: array of arguments
 * Return: void
 */
void handle_unsetenv(char **args)
{
	char *err = "Usage: unsetenv Variable\n";
	int len = _strlen(err);

	if (args[1] == NULL)
		write(STDERR_FILENO, err, len);
	if (unsetenv(args[1]) != 0)
		perror("unsetenv error");
}
