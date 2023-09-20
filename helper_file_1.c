#include "simple_shell.h"

/**
 *shell_printer - prints a string to stdout
 *@sstring: the string to be printed
 *@output_stream: the stream to print out to
 *
 *Return: void, return nothing
 */

void shell_printer(char *sstring, int output_stream)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		while (sstring[i] != '\0')
		{
			write(output_stream, &sstring[i], 1);
			i++;
		}
	}
}
