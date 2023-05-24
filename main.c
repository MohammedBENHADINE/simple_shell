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
		parsed_input = parse(user_input);

		execute(parsed_input, argv[0]);
	}

	free_td(parsed_input);
	free(user_input);

	return (0);
}
