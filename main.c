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
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokenize(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				handle_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				dir_changes(command[1]);
			else
				execute_child(command, argv[0], envp, loops);
		}
		fflush(stdin);
		buffer = NULL, buffer_size = 0;
	}
}
