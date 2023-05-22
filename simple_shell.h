#ifndef S_SHELL_H
#define S_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_TOKEN 512
#define MAX_INPUT_SIZE 1024

/**
 * struct error - the list of error
 * @code: the error code
 * @txt: the error text
 * Description: this struct allow us to handle the different error
 * of all the project
 * We may call the code, add, move and fix the error in one place.
 */
typedef struct error
{
	int code;
	char *txt;
} err_t;

void error(int);
#endif
