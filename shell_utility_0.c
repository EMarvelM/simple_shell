#include "simple_shell.h"

/**
 * parse_command - determines the type of the command
 * @command: command to be parsed
 *
 * Return: constant representing the type of the command
 * Description -
 * EXT_CMD (1) represents commands like /bin/ls
 * INT_CMD (2) represents commands like exit, env
 * PTH_CMD (3) represents commands found in the PATH like ls
 * INVD_CMD (-1) represents invalid commands
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

/**
 * execute_command - executes a command based on it's type
 * @cmd_token: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: void
 */
void execute_command(char **cmd_token, int command_type)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
	void (*func)(char **command);

	/* Execute external or path-based command*/
	if (command_type == EXT_CMD || command_type == PTH_CMD)
	{
		char *command_path = (command_type == EXT_CMD) ? cmd_token[0] : check_path(cmd_token[0]);
		if (execve(command_path, cmd_token, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	/* Execute internal command*/
	else if (command_type == INT_CMD)
	{
		func = get_cmd_function(cmd_token[0]);
		func(cmd_token);
	}
	/* Invalid command*/
	else if (command_type == INVD_CMD)
	{
		shell_printer(program_name, STDERR_FILENO);
		shell_printer(": 1: ", STDERR_FILENO);
		shell_printer(cmd_token[0], STDERR_FILENO);
		shell_printer(": not found\n", STDERR_FILENO);
		status = 127;
	}
	}
}
