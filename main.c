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
	size_t buffer_size = 0;
	ssize_t checked_chars = 0;
	int loops = 0;

	(void)checked_chars;
	(void)buffer_size;

	signal(SIGINT, handle_signal);

	while (1)
	{
		loops++;

		buffer = read_ia();

		if (buffer != NULL)
		{
			command = parse(buffer);


			execute(command, argv[0], envp, loops);


		}

		buffer = NULL, buffer_size = 0;
	}
}
