#include "main.h"
/**
 * _strdup - allocates sufficient memory for a copy of the string s
 * @s: string
 * Return: NULL-terminated string
 */
char *_strdup(char *s)
{
	size_t len, i;
	char *duplicate;

	if (s == NULL)
		return (NULL);
	len = _strlen(s) + 1;
	duplicate = malloc(len);
	if (duplicate != NULL)
	{
		for (i = 0; i < len; i++)
			duplicate[i] = s[i];
	}
	return (duplicate);
}

/**
 * exec_alias - prints a list of all aliases
 * @args: user input
 */
void exec_alias(char *args)
{
	char *token = _strtok(args, " ");
	int i = 0, j;
	struct Alias aliases[MAX_ALIASES];
	int numAliases = 0;

	while (token != NULL)
	{
		token = _strtok(NULL, " ");
	}
	if (i == 1)
	{
		for (j = 0; j < numAliases; j++)
			printf("%s='%s'\n", aliases[j].name, aliases[j].value);
	} else if (i == 2)
	{
		for (j = 0; j < numAliases; j++)
		{
			if (_strcmp(&args[1], aliases[j].name) == 0)
				printf("%s='%s'\n", aliases[j].name, aliases[j].value);
		}
		printf("alias: %d not found\n", args[1]);
	} else if (i == 3)
	{
		if (numAliases < MAX_ALIASES)
		{
			aliases[numAliases].name = _strdup(args);
			token = _strtok(NULL, "=");
			aliases[numAliases].value = _strdup(token);
			numAliases++;
		} else
			printf("Error: maximum number of aliases reached\n");
	} else
		printf("Error: alias [name[='value'] ...]\n");
}
