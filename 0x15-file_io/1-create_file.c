#include "main.h"

/**
 * create_file - creates a new file and writes text content to it
 * @filename: the name of the file to create
 * @text_content: the text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int numletters;
	int file_mode;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (numletters = 0; text_content[numletters]; numletters++)
		;

	file_mode = write(fd, text_content, numletters);
	if (file_mode == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
