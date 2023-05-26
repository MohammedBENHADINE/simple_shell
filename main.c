#include "simple_shell.h"
/**
 * main - the main function of the hsh project
 * @argc: number of args
 * @argv: pointer on args
 * @envp: pointer on env vars
 *
 * Return: 0 on Succcess, 8 on Always
 */
int main(__attribute((unused)) int argc, char *argv[], char *envp[])
{
	char *user_input = NULL;
	char **command = NULL;
	int cycl = 0;

	signal(SIGINT, handle_signal);

	while (1)
	{
		cycl++;

		switch (isatty(STDIN_FILENO))
		{
		case 0: /*non-interactive mode*/
			user_input = read_nia();
			command = parse(user_input);
			execute(command, argv[0], envp, cycl);
			break;
		case 1: /*interactive mode*/
			user_input = read_ia();
			command = parse(user_input);
			execute(command, argv[0], envp, cycl);
			break;
		}

		free_memory(command);
		free(user_input);
	}

	free_memory(command);
	free(user_input);
}
