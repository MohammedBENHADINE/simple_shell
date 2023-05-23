#include "simple_shell.h"
/**
 * main - the main function of the hsh project
 * @argc: number of args
 * @argv: pointer on args
 * @envp: pointer on env vars
 *
 * Return: 0 on Succcess, 8 on Always
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
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);
		if (getline(&buffer, &size, stdin) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			perror("fork");
		if (pid == 0)
		{
			token = strtok(buffer, "\n");
			if (execve(token, argv, envp) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(&status);
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}
