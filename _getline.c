#include "main.h"
#define SIZE 256
/**
 * _getline -  reads a line of input from the user,
 * and it automatically allocates memory for the line
 *
 * @line: ** that stores the memory containing the line
 * @len: line len
 * @stream: file stream
 * Return: number of characters read\n, -1 on error
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	size_t limit = SIZE, i = 0;
	int arg;

	if (*len == 0)
	{
		*line = (char *)malloc(limit);
		if (*line == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	} while ((arg = fgetc(stream)) != EOF && arg != '\n')
	{
		(*line)[i++] = (char)arg;
		if (i == limit - 1)
		{
			limit *= 2;
			*line = (char *)realloc(*line, limit);
			if (*line == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
	}
	if (i == 0 && arg == EOF)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	(*line)[i] = '\0';
	return ((ssize_t)i);
}
