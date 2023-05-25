#include "simple_shell.h"
#include <sys/stat.h>

/**
 * search_cmd - searches for the command to execute in
 * the environment PATH.
 * @str: the string from which to search.
 *
 * Return: the path of the command if found.
 * Otherwise returns NULL.
*/
char *search_cmd(const char *str)
{
	char *dlm = ":";
	char **str_arr = { NULL };
	char *cmd_path = NULL;
	int i = 0;
	struct stat st;

	(void)i;
	(void)str_arr;
	(void)dlm;

	if (stat(str, &st) == 0)
	{
		cmd_path = str_dup(str);
		return (cmd_path);
	}


	/**
	 * if (stat(str, &st) == 0)
		return (str_dup(str));

	str_arr = extract_tokens(getenv("PATH"), dlm);

	while (str_arr[i] != NULL)
	{
		cmd_path = str_concat(str_arr[i], str_concat("/", str));
		if (stat(cmd_path, &st) == 0)
			return (cmd_path);
		i++;
	}
	*/

	return (NULL);
}
