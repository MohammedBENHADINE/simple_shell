#include "simple_shell.h"

/**
 * main - the main function of the hsh project
 *
 * Return: 0 Always
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer;
	char prompt[] = "#Cisfun$ ";
	char *token;
	int status = argc;
	size_t size = MAX_INPUT_SIZE;
	pid_t pid;

	buffer = malloc(MAX_INPUT_SIZE);
	if (!buffer)
	{
		printf("error");
		exit(1);
	}
	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);
		if (fgets(buffer, size, stdin) == NULL)
		{
			printf("./shell: error reading from stdin");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
			printf("./shell : can't fork\n");
		if (pid == 0)
		{
			token = strtok(buffer, "\n");
			if (execve(token, argv, envp) == -1)
				printf("./shell : No such file or directory\n");
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
