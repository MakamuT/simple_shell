#include "main.h"
#define CMD_MAX 100
/**
 * file_cmd - takes a file as a command line argument
 * @filename: filename
 * Return: void
 */
void file_cmd(const char *filename)
{
	int fd;
	char cmd[CMD_MAX];
	ssize_t readBytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Can't open file");
		exit(EXIT_FAILURE);
	}
	while ((readBytes = read(fd, cmd, sizeof(cmd))) > 0)
	{
		if (write(STDOUT_FILENO, cmd, readBytes) != readBytes)
		{
			perror("Error: Can't write command");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
}
