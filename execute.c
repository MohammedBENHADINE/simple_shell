#include "simple_shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * execute - executes a command in a new process
 * @in_arr: command and argument list.
 * @self: pointer arg[0] argument.
 *
 * Return: 1 on exit command 0 otherwise.
*/
int execute(char **in_arr, char *self)
{
	char *cmd = NULL;
	int pid, status;

	cmd = get_cmd(in_arr, self);

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
