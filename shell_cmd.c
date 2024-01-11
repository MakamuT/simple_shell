#include "main.h"
#define CMD_MAX 100
/**
 * _strcmp - compares two strings
 * @s1: first parameter
 * @s2: second parameter
 * Return: returns 0 if s1 == s2
 * -ve value if s1 < s2
 * +ve value if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

/**
 * shell_cmd - handles simple shell commands
 * @cmd: command to be executed
 * Return: void
 */
void shell_cmd(char **cmd)
{
	char *dir, *cmd_cp;
	int status;

	cmd_cp = strdup(cmd[0]);
	if (cmd_cp == NULL)
		perror("strdup failed");
	dir = strtok(cmd_cp, " ");
	fflush(stdout);
	if (dir != NULL && _strcmp(cmd[0], "cd") == 0)
	{
		dir = strtok(cmd_cp + 3, " ");
		handle_cd(dir);
	}
	if (access(cmd[0], X_OK) == 0)
		file_cmd(cmd[0]);
	if (_strcmp(cmd[0], "exit") == 0)
	{
		status = (cmd[1] != NULL) ? atoi(cmd[1]) : 0;
		handle_exit(status);
	}
	if (_strcmp(cmd[0], "env") == 0)
		handle_env();
	if (_strcmp(cmd[0], "setenv") == 0)
		handle_setenv(cmd);
	if (_strcmp(cmd[0], "unsetenv") == 0)
		handle_unsetenv(cmd);
	else
		execmd(cmd);
	free(cmd_cp);
}
