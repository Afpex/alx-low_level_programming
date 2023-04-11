#include "main.h"

/**
 * create_file - Function that creates a file.
 * @filename: The name of the file to create.
 * @text_content: Is a string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int i;
	char *buf;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		text_content = "";

	fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0600);
	if (fd < 0)
	{
		if (errno == EEXIST)
		{
			fd = open(filename, O_WRONLY | O_TRUNC);
			if (fd == -1)
				return (-1);
		}
		else
			return (-1);
	}
	buf = malloc(sizeof(char) * (strlen(text_content) + 1));
	if (buf == NULL)
	{
		close(fd);
		return (-1);
	}
	for (i = 0; text_content[i] != '\0'; i++)
		buf[i] = text_content[i];
		buf[i] = '\0';

		if (write(fd, buf, strlen(buf)) == -1)
		{
			close(fd);
			free(buf);
			return (-1);
		}
	close(fd);
	free(buf);
	return (1);
}
