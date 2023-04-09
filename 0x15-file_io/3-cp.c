#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * file_err - check for file errors
 * @file_from: file descriptor of the source file
 * @file_to: file descriptor of the destination file
 * @argc: the number of arguments (must be 3)
 * @argv: strings of argument in array
 * Return: no return.
 */
void file_err(int file_from, int file_to, int argc, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * main - program that copies files from one file to other
 * @argc: the number of arguments (must be 3)
 * @argv: strings of argument in array
 * Return: 0 on success, exit with error code on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, num_read, num_written, close_from, close_to;
	char buffer[BUFFER_SIZE];

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	file_err(file_from, file_to, argc, argv);

	do {
		num_read = read(file_from, buffer, BUFFER_SIZE);
		if (num_read == -1)
		{
			file_err(-1, 0, argc, argv);
		}
		num_written = write(file_to, buffer, num_read);
		if (num_written == -1)
		{
			file_err(0, -1, argc, argv);
		}
	} while (num_read > 0);

	close_from = close(file_from);
	if (close_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	close_to = close(file_to);
	if (close_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}

