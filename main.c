#include "simple_shell.h"
#include <stdio.h>

/**
 * main - the main entry point to the custom
 * simple shell
 * @argc: number of arguments.
 * @argv: list of arguments.
 *
 * Return: 0 within the current process,
 * otherwise does not return.
*/
int main(int argc, char **argv)
{
	char *user_input = NULL;
	char **parsed_input = { NULL };

	(void)argc;

	while (1)
	{
		user_input = read_input();

		if (check_input(user_input) == 0)
		{
			parsed_input = parse(user_input);
			execute(parsed_input, argv[0]);
		}

		switch (check_input(user_input))
		{
		case 0:
			parsed_input = parse(user_input);
			execute(parsed_input, argv[0]);
			break;
		case 2:
			free(user_input);
			exit(EXIT_SUCCESS);
			break;
		}
	}

	free_td(parsed_input);
	free(user_input);

	return (0);
}
