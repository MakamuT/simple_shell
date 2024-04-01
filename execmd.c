#include "main.h"
#define MAX_ARGS 256
/**
 * execmd - executes given commands
 * @argv: char
 * Return: 0
 */
void execmd(char *argv)
{
	char *token = _strtok(argv, " \t\n"), *varName;
	struct Envar envars[MAX_ALIASES];
	int numEnvars = 0;
	pid_t pid = fork();
	char *cmd[MAX_ARGS], *varValue;
	int i;
	int status;

	cmd[0] = parse_cmd(argv);
	cmd[1] = NULL;
	while (token != NULL)
	{
		if (token[0] == '$')
		{
			varName = token + 1;
			varValue = NULL;
			for (i = 0; i < numEnvars; i++)
			{
				if (_strcmp(varName, envars[i].name) == 0)
				{
					varValue = envars[i].value;
					break;
				}
			}
			if (varValue != NULL)
				printf("%s ", varValue);
			else
				printf("%s ", token);
		} else if (token[0] == '#')
			break;
		printf("%s ", token);
		token = _strtok(NULL, " \t\n");
	}
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		perror("Error:");
	} else
		waitpid(pid, &status, 0);
}
