#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*constants*/
#define INVD_CMD -1
#define INT_CMD 2
#define EXT_CMD 1
#define PTH_CMD 3

#define minimum_Value(a, b) (((a) < (b)) ? (a) : (b))

/**
 *struct mapping_function - a struct that maps command name to a function
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct mapping_function
{
	char *command_name;
	void (*func)(char **command);
} mapping_to_function;

extern char **environ;

/* Store the user input */
extern char *user_input;
extern char **my_cmds;
