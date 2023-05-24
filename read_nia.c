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
	char *line_ptr = NULL;
	size_t line_size = 0;

	if (getline(&line_ptr, &line_size, stdin) == EOF)
	{
		if (str_len(line_ptr) == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			fflush(stdout);
			free(line_ptr);
			exit(EXIT_SUCCESS);
		}

		free(line_ptr);
		exit(EXIT_SUCCESS);
	}

	return (line_ptr);
}
