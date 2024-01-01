#include "main.h"
/**
 * execmd - executes given commands
 * @argv: char
 * Return: 0
 */

void execmd(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
