#include "shell.h"

/**
 * _strcmp - This function compares two strings.
 *
 * @str1: The first pointer string to compare
 * @str2: The second pointer string to compare
 * Return: 1 if strings are the same, 0 if not
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 == *str2);
}


/**
 * _strlen - A function that finds the length of the string
 *
 * @str: The input string
 * Return: The length of the string
 */
unsigned int _strlen(char *str)
{
	unsigned int length = 0;

	while (str[length])
		length++;

	return (length);
}


/**
 * _strcpy - This function copies a string to another string.
 *
 * @dest: The pointer to the copy pointer string
 * @src: The pointer to the string to copy
 * Return: A pointer to copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *mix = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (mix);
}


/**
 * _strcat - This function concatenates two strings.
 *
 * @dest: The output string
 * @src: The input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *mix = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (mix);
}


/**
 * _strint - This function converts a string to an integer.
 *
 * @str: The input string.
 * Return: An integer from the conversion.
 */
int _strint(char *str)
{
	int sign = 1;
	unsigned int total = 0;

	if (str == NULL)
		return (0);

	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		total = total * 10 + (*str - '0');
		str++;
	}

	return (sign * total);
}

