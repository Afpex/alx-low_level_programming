#include "main.h"

/**
 * read_textfile - Reads a file and prints it to the POSIX stdout.
 * @filename: The name of the file that needs to be read.
 * @letters: Is the number of letters the function should read.
 *
 * Return: The actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_desc, i, bytes_read;
	char *text;

	if (!filename)
	return (0);

	text = malloc(sizeof(char) * letters);
	if (!text)
	return (0);

	file_desc = open(filename, O_RDONLY);
	if (file_desc < 0)
	{
	free(text);
	return (0);
	}

	bytes_read = read(file_desc, text, letters);
	if (bytes_read < 0)
	{
	close(file_desc);
	free(text);
	return (0);
	}

	for (i = 0; i < bytes_read; ++i)
	{
	if (putchar(text[i]) < 0)
	{
	close(file_desc);
		free(text);
	return (0);
	}
	}

	close(file_desc);
	free(text);
	return (bytes_read);
}
