#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "simple_shell# ";
	char *lineptr = NULL, *ptr_cp = NULL, *toks;
	size_t n = 0;
	ssize_t char_read;
	const char *delim = "\n";
	int num_tok = 0, s;

	(void)argc;
	while (1)
	{
		printf("%s", prompt);
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		ptr_cp = malloc(sizeof(char) * char_read);
		if (ptr_cp == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(ptr_cp, lineptr);
		toks = strtok(lineptr, delim);
		while (toks != NULL)
		{
			num_tok++;
			toks = strtok(NULL, delim);
		}
		num_tok++;

		argv = malloc(sizeof(char *) * num_tok);
		toks = strtok(ptr_cp, delim);
		for (s = 0; toks != NULL; s++)
		{
			argv[s] = malloc(sizeof(char) * strlen(toks));
			strcpy(argv[s], toks);
			toks = strtok(NULL, delim);
		}
		argv[s] = NULL;
		shell_cmd(argv);
		execmd(argv);
	}
	free(ptr_cp);
	free(lineptr);
	return (0);
}
