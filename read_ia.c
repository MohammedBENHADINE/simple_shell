#include "simple_shell.h"
#include <stdio.h>

/**
 * read_ia - reads input from stdin.
 * in interactive mode
 *
 * Return: number of characters read excluding '\0'.
*/
char *read_ia(void)
{
	char *line_ptr = NULL;
	size_t line_size = 0;
	char *prompt = "my_shell$ ";

	write(STDOUT_FILENO, prompt, str_len(prompt));

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
