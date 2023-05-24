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
		switch (isatty(STDIN_FILENO))
		{
		case 0: /*non-interactive mode*/
			user_input = read_nia();
			parsed_input = parse(user_input);
			execute_nia(parsed_input, argv[0]);
			break;
		case 1: /*interactive mode*/
			user_input = read_ia();
			parsed_input = parse(user_input);
			execute_ia(parsed_input, argv[0]);
			break;
		}
	}

	free_td(parsed_input);
	free(user_input);

	return (0);
}
