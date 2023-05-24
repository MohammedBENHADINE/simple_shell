#include "simple_shell.h"
#include <stdio.h>

/**
 * get_cmd - validates command and checks if it exists.
 * handles any environment related operations.
 * @in: array of tokens (sub-strings)
 * @self: pointer to argv[0] argument from main.
 *
 * Return: command string.
*/
char *get_cmd(char **in, char *self)
{
	char *cmd = NULL;

	cmd = search_cmd(in[0]);

	if (cmd == NULL)
	{
		perror(self);
		free_td(in);
		return (NULL);
	}

	return (cmd);
}
