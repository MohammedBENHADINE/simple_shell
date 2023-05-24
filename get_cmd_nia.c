#include "simple_shell.h"
#include <stdio.h>

/**
 * get_cmd_nia - validates command and checks if it exists.
 * handles any environment related operations.
 * @in: array of tokens (sub-strings)
 * @self: pointer to argv[0] argument from main.
 *
 * Return: command string.
*/
char *get_cmd_nia(char **in, char *self)
{
	char *cmd = NULL;
	char *err_msg = str_concat(self, ": 1: ");
	char *err_msg2 = str_concat(in[0], ": ");
	char *err_msg3 = str_concat(err_msg, err_msg2);
	char *err_msg4 = str_concat(err_msg3, "not found");

	cmd = search_cmd(in[0]);

	if (cmd == NULL)
	{
		fflush(stdout);
		write(STDOUT_FILENO, err_msg4, _strlen(err_msg4));
		free_td(in);
		return (NULL);
	}

	return (cmd);
}
