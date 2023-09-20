#include "simple_shell.h"

/**
 *current_env - prints the current_environement
 *@cmd_token: command entered
 *
 *Return: void
 */
void current_env(char **cmd_token __attribute__((unused)))
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		/* Loop through environment variables and print them */
		for (i = 0; environ[i] != NULL; i++)
		{
			shell_printer(environ[i], STDOUT_FILENO);
			shell_printer("\n", STDOUT_FILENO);
		}
	}
}
