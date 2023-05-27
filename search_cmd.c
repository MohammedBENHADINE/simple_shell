#include "simple_shell.h"
#include <sys/stat.h>

/**
 * search_cmd - searches for the command to execute in
 * the environment PATH.
 * @str: the string from which to search.
 * @env: environment variables.
 *
 * Return: the path of the command if found.
 * Otherwise returns NULL.
*/
char *search_cmd(char *str, char **env)
{
	char *dlm = ":";
	char **str_arr = { NULL };
	char *cmd_path = NULL;
	int i = 0;
	struct stat st;

	if (str == NULL)
		return (NULL);

	if (count_tokens(str, dlm) == 0)
		return (NULL);

	if (stat(str, &st) == 0)
		return (str);

	str_arr = _dirsPATH(env);

	while (str_arr[i] != NULL)
	{
		cmd_path = _strcat(str_arr[i], _strcat("/", str));
		if (stat(cmd_path, &st) == 0)
			return (cmd_path);
		i++;
	}

	return (NULL);
}
