#include "main.h"

/**
 * my_getline - Read a line from a file stream.
 *
 * Return: buffer.
 */

char *my_getline(void)
{
	int n_char;
	size_t buffer_size;
	char *buffer;

	buffer_size = 0;
	buffer = NULL;
	write(1, "#cisfun$ ", 9);
	n_char = getline(&buffer, &buffer_size, stdin);
	if (n_char == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
