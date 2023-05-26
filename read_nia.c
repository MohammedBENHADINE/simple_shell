#include "simple_shell.h"
#include <stdio.h>

/**
 * read_nia - reads input from stdin.
 * in non-interactive mode.
 *
 * Return: number of characters read excluding '\0'.
*/
char *read_nia(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t checked_chars = 0;

	checked_chars = getline(&buffer, &buffer_size, stdin);

	if (checked_chars == EOF)
	{
		handle_eof(buffer);
	}
	else if (*buffer == '\n')
	{
		free(buffer);
		buffer = NULL;
	}

	return (buffer);
}
