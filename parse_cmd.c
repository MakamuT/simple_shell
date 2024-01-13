#include "main.h"
/**
 * parse_cmd - removes newline character
 * @cmd: user input
 * Return: command parsed
 */
char *parse_cmd(char *cmd)
{
	size_t len = _strlen(cmd);

	if (len > 0 && cmd[len - 1] == '\n')
		cmd[len - 1] = '\0';
	return (cmd);
}
