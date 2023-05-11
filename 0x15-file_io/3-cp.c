#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *file);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates a buffer of size 1024 bytes.
 * @file: The name of the file for which the buffer is allocated.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *allocate_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with the following error codes:
 *   - 97 if the argument count is incorrect.
 *   - 98 if the source file does not exist or cannot be read.
 *   - 99 if the destination file cannot be created or written to.
 *   - 100 if any file descriptor cannot be closed.
 */
int main(int argc, char *argv[])
{
	int source_file, destination_file, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	source_file = open(argv[1], O_RDONLY);
	read_bytes = read(source_file, buffer, 1024);
	destination_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_file == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(destination_file, buffer, read_bytes);
		if (destination_file == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(source_file, buffer, 1024);
		destination_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_file_descriptor(source_file);
	close_file_descriptor(destination_file);

	return (0);
}
