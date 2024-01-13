#include "main.h"
/**
 * read_line - reads user input from stdin
 * Return: read line
 */
char *read_line(void)
{
	size_t size = 0;
	char *line = NULL;
	ssize_t read_c;

	read_c = getline(&line, &size, stdin);
	if (read_c == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	if (read_c > 0 && line[read_c - 1] == '\n')
		line[read_c - 1] = '\0';
	return (line);
}
