#include "simple_shell.h"

		char **my_cmds = NULL;
		char *user_input = NULL;
		char *program_name = NULL;
		int status = 0;

/**
 * main - executes the main simple_shell program
 * @argc: total number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies the functions in utils and helpers
 * implements EOF (End Of File)
 * Print an error if there is a failure
 * Return: ALways (0) on success
 *
 * Description:
 * the extended functions for main.c
 */
int main(int argc __attribute__((unused)), char **argv)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		char **current_cmd = NULL;
		int i, cmd_type = 0;
		size_t n = 0;

		signal(SIGINT, ctrl_c_handler);
		program_name = argv[0];
		while (1)
		{
			uninteractive();
			shell_printer("$:) ", STDOUT_FILENO);
			if (getline(&user_input, &n, stdin) == -1)
			{
				free(user_input);
				exit(status);
			}
				newline_remover(user_input);
				remove_comment(user_input);
				my_cmds = str_tokenizer(user_input, ";");

			for (i = 0; my_cmds[i] != NULL; i++)
			{
				current_cmd = str_tokenizer(my_cmds[i], " ");
				if (current_cmd[0] == NULL)
				{
					free(current_cmd);
					break;
				}
				cmd_type = parse_command(current_cmd[0]);
				setup_init(current_cmd, cmd_type);/*initializer*/
				free(current_cmd);
			}
			free(my_cmds);
		}
		free(user_input);

		return (status);
	}
	return (0);
}
