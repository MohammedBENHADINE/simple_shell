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
	char *buffer = NULL;
	char **command = NULL;
	int cycls = 0;

	signal(SIGINT, handle_signal);

	while (1)
	{
		buffer = read_ia();
		command = parse(buffer);
		execute(command, argv[0], envp, ++cycls);
	}
}
