#include "simple_shell.h"
/**
 * free_memory - This function that frees all the memory
 * allocated for commands.
 *
 * @command: Pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_memory(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	for (; command[i] != NULL; i++)
	{
		free(command[i]);
		command[i] = NULL;
	}
	free(command);
}


/**
 * freeMem_and_exit - A function frees all the memory
 * allocated and exit.
 *
 * @command: The pointer to allocated commands memory to free.
 * Return: Nothing.
 */
void freeMem_and_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	for (; command[i] != NULL; i++)
		free(command[i]);

	free(command);
	exit(EXIT_FAILURE);
}
/**
 * tokenize - A function tokenizes string into multiple commands.
 *
 * @buffer: The string to tokenize.
 * @delim: The delimiter to use.
 * Return: An array of tokens.
 */
char **tokenize(char *buffer, const char *delim)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_memory(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, delim);
	while (token != NULL)
	{
		commands[i] = malloc(_strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_memory(commands);
			return (NULL);
		}
		_strcpy(commands[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
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

	while (1)
	{
		loops++;
		prompt_handler();
		signal(SIGINT, handle_signal);
		checked_chars = getline(&buffer, &buffer_size, stdin);
		if (checked_chars == EOF)
			handle_eof(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
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
