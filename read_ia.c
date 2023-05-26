#include "simple_shell.h"

/**
 * read_ia - reads input from stdin.
 * in interactive mode
 *
 * Return: number of characters read excluding '\0'.
*/
char *read_ia(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t checked_chars = 0;
	char *prompt = "#cisfun$ ";

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, prompt, _strlen(prompt));

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

	if (_strlen(buffer) == (unsigned int)_strspn(buffer, " ") + 1)
	{
		free(buffer);
		buffer = NULL;
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
