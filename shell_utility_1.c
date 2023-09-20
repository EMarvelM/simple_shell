#include "simple_shell.h"

/**
 * Auth: Egbe Marvelous M
 * 		 DC Ozioma
 *
 * Description:
 * the extended functions for main.c
 */

/**
 * check_path - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */

char *check_path(char *command)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		char **path_array = NULL;
		char *temp = NULL, *temp2 = NULL, *path_copy = NULL;
		char *path = _getenv("PATH");
		int i = 0, num_directories = 0;

		if (path == NULL || _stringlen(path) == 0)
			return (NULL);

		/* Allocate memory for path_copy*/
		path_copy = malloc(sizeof(*path_copy) * (_stringlen(path) + 1));
		_strcopy(path, path_copy);

		/* Tokenize path into directories*/
		path_array = str_tokenizer(path_copy, ":");

		/* Count the number of directories */
		for (num_directories = 0; path_array[num_directories] != NULL; num_directories++)
			;

		/* Iterate through directories to find the command*/
		for (i = 0; i < num_directories; i++)
		{
			temp2 = _str_concat(path_array[i], "/");
			temp = _str_concat(temp2, command);

			/* Check if concatenated path is accessible*/
			if (access(temp, F_OK) == 0)
			{
				free(temp2);
				free(path_array);
				free(path_copy);
				return (temp);
			}

			free(temp);
			free(temp2);
		}

		/* Clean up and return NULL if not found*/
		free(path_copy);
		free(path_array);
		return (NULL);
	}
	return (NULL);
}


/**
 * get_cmd_function - retrieves a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*get_cmd_function(char *command))(char **)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		size_t i = 0;
		
		mapping_to_function mapping[] = {
			{"env", current_env}, {"exit", exiting_program}
		};

		/*Iterate through the mapping and using a while loop*/
		while (i < sizeof(mapping) / sizeof(mapping[0]))
		{
			if (_str_comp(command, mapping[i].command_name) == 0)
				return mapping[i].func;

			i++;
		}

		return (NULL);
	}

	return (NULL);
}
