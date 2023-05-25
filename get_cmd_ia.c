#include "simple_shell.h"
#include <stdio.h>

/**
 * get_cmd_ia - validates command and checks if it exists.
 * handles any environment related operations.
 * @in: array of tokens (sub-strings)
 * @self: pointer to argv[0] argument from main.
 *
 * Return: command string.
*/
char *get_cmd_ia(char **in, char *self)
{
	char *cmd = NULL;

	

	cmd = search_cmd(in[0]);

	if (cmd == NULL || in[1] != NULL)
	{
		errno = 2;
		fflush(stdout);
		perror(self);

		return (NULL);
	}

	return (cmd);
}
