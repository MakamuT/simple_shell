#include "main.h"
#define F_SIZE 1000
/**
 * file_cmd - takes a file as a command line argument
 * @filename: filename
 * Return: void
 */
void file_cmd(const char *filename)
{
	int fd;
	char buff[F_SIZE], *cmd;
	ssize_t readBytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Can't open file");
		exit(EXIT_FAILURE);
	}
	while ((readBytes = read(fd, buff, sizeof(buff))) > 0)
	{
		cmd = parse_cmd(buff);
		execmd(cmd);
		free(cmd);
	}
	if (readBytes == -1)
	{
		perror("Error: Can't write command");
		exit(EXIT_FAILURE);
	}
	close(fd);
}
