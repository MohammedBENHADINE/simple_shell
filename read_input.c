#include "simple_shell.h"
#include <stdio.h>

/**
 * read_input - reads input from stdin.
 *
 * Return: number of characters read excluding '\0'.
*/
char *read_input(void)
{
	char *line_ptr = NULL;
	size_t line_size = 0;
	ssize_t nread;
	char *prompt = "my_shell$ ";

	(void)nread;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, prompt, str_len(prompt));

	if (getline(&line_ptr, &line_size, stdin) == EOF)
	{
		if (str_len(line_ptr) == 0)
		{
			fflush(stdout);
			write(STDOUT_FILENO, "\n", 1);
			free(line_ptr);
			exit(EXIT_SUCCESS);
		}

		free(line_ptr);
		exit(EXIT_SUCCESS);
	}

	return (line_ptr);
}
