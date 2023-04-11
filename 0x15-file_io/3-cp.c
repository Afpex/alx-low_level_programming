#include "main.h"

/**
 * error_handling - handles file error cases
 * @file_from: file from descriptor
 * @file_to: file to descriptor
 * @filename: filename
 *
 * Return: Nothing
 */
void error_handling(int file_from, int file_to, char *filename[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename[2]);
		exit(99);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: arguments array
 *
 * Return: 0 on success, 97-100 on error
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t n_read, n_write;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	error_handling(file_from, file_to, argv);

	do {
		n_read = read(file_from, buffer, 1024);
		if (n_read == -1)
			error_handling(-1, 0, argv);
		n_write = write(file_to, buffer, n_read);
		if (n_write == -1 || n_write != n_read)
			error_handling(0, -1, argv);
	} while (n_read == 1024);

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
