#include "simple_shell.h"

/** parse_command - determines the type of the command
 * @command: command to be parsed
 *
 * Return: constant representing the type of the command
 * Description -
 * 		 EXT_CMD (1) represents commands like /bin/ls
 *		 INT_CMD (2) represents commands like exit, env
 *		 PTH_CMD (3) represents commands found in the PATH like ls
 *		 INVD_CMD (-1) represents invalid commands
 */
int parse_command(char *command)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;
		char *internal_command[] = {"env", "exit", NULL};
		char *path = NULL;

		/* Check if the command is an external command*/
		for (i = 0; command[i] != '\0'; i++)
		{
			if (command[i] == '/')
				return (EXT_CMD);
		}

		/* Check if the command is an internal command */
		for (i = 0; internal_command[i] != NULL; i++)
		{
			if (_str_comp(command, internal_command[i]) == 0)
				return (INT_CMD);
		}

		/* Check if the command is found in the PATH*/
		path = check_path(command);
		if (path != NULL)
		{
			free(path);
			return (PTH_CMD);
		}

		return (INVD_CMD); /* Invalid command*/
	}
	return (0);
}
