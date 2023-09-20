#include "simple_shell.h"

/**
 *_strtok_r - tokenizes a string
 *@sstring: the text string to be tokenized
 *@_delimita: word delimiter to be used to tokenize the string
 *@save_ptr: pointer to be used to keep track of the next token
 *
 *Return: The next available token
 */
char *_strtok_r(char *sstring, char *_delimita, char **save_ptr)
{
	char *finish;

	if (sstring == NULL)
		sstring = *save_ptr;

	if (*sstring == '\0')
	{
		*save_ptr = sstring;
		return (NULL);
	}

	/* Skip leading delimiters*/
	while (*sstring != '\0' && _strchr(_delimita, *sstring) != NULL)
	{
		sstring++;
	}

	if (*sstring == '\0')
	{
		*save_ptr = sstring;
		return (NULL);
	}

	finish = sstring;

	/* Find the end of the token*/
	while (*finish != '\0' && _strchr(_delimita, *finish) == NULL)
	{
		finish++;
	}

	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (sstring);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (sstring);
}


/**
 * shell_isatty - my tester for shell (shell_isatty)
 * @fd: file descriptor
 *
 * Return: always success
*/
int shell_isatty(int fd)
{
	static int call_count;

	call_count++;

	/* printf(" ------ -   --- -- - - - - -%d\n", call_count); */
	/* Best Debugger */

	if (isatty(fd))
	{
		return (1);  /* Return true if isatty is true */
	}

	else
	{
		return (1);  /* Return true even if isatty is false */
	}
}
