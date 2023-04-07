#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @fn: the name of the file to read
 * @l: the number of letters to read and print
 *
 * Return: the actual number of letters it could read and print, or 0 if there
 * was an error opening, reading, or writing the file
 */
ssize_t read_textfile(const char *fn, size_t l)
{
	int fd;
	ssize_t num_read, num_written;
	char *buffer;

	if (fn == NULL)
		return (0);

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * (l + 1));
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	num_read = read(fd, buffer, l);
	if (num_read == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	buffer[num_read] = '\0';

	num_written = write(STDOUT_FILENO, buffer, num_read);
	if (num_written == -1 || num_written != num_read)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	close(fd);
	free(buffer);

	return (num_written);
}

