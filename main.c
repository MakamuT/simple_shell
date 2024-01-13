#include "main.h"
/**
 * main - entry point of program
 * Return: 0 on success, -1 on error and updates errno
 */
int main(void)
{
	char *lineptr = NULL, *ptr_cp = NULL, *toks, **argv_c;
	size_t n = 0;
	ssize_t char_read;
	const char *delim = "\n";
	int num_tok = 0, s;

	while (1)
	{
		printf("simple_shell# ");
		char_read = _getline(&lineptr, &n, stdin);
		if (char_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		} ptr_cp = malloc(sizeof(char) * char_read);
		if (ptr_cp == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		} strcpy(ptr_cp, lineptr);
		toks = _strtok(lineptr, delim);
		while (toks != NULL)
		{
			num_tok++;
			toks = _strtok(NULL, delim);
		} num_tok++;
		argv_c = malloc(sizeof(char *) * num_tok);
		toks = _strtok(ptr_cp, delim);
		for (s = 0; toks != NULL; s++)
		{
			argv_c[s] = malloc(sizeof(char) * (strlen(toks) + 1));
			strcpy(argv_c[s], toks);
			toks = _strtok(NULL, delim);
		} argv_c[s] = NULL;
		shell_cmd(argv_c);
	} free(argv_c);
	free(ptr_cp);
	free(lineptr);
	return (0);
}
