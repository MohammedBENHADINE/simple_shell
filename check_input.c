#include "simple_shell.h"

/**
 * check_input - checks for special input cases from
 * stdin to handle accordingly.
 * @in_str: input string.
 *
 * Return: int code.
*/
int check_input(char *in_str)
{
	if (_strcmp(in_str, "\n") == 0)
		return (1);
	else if (_strcmp(in_str, "exit\n") == 0)
		return (2);

	return (0);
}
