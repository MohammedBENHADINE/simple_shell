#include "simple_shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * execute_nia - executes a command in a new process
 * @in_arr: command and argument list.
 * @self: pointer arg[0] argument.
 *
 * Return: 1 on exit command 0 otherwise.
*/
int execute_nia(char **in_arr, char *self)
{
	char *cmd = NULL;
	int pid, status;

	if (in_arr == NULL)
		return (0);

	cmd = get_cmd_nia(in_arr, self);

	if (cmd == NULL)
		return (0);

	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd, in_arr, __environ) == -1)
		{
			free_td(in_arr);
			free(cmd);
			perror("error: execve()");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		return (0);
	}
	return (0);
}
