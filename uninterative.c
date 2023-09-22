#include "simple_shell.h"

/**
 * uninteractive - handles uninteractive mode
 *
 * Return: void
 */
void uninteractive(void)
{
    char **current_cmd = NULL;
    int i, cmd_type = 0;
    size_t n = 0;

    if (!(isatty(STDIN_FILENO)))
    {
        while (1)
        {
            char *line = my_getline(STDIN_FILENO);

            if (!line)
                break; // End of input

            newline_remover(line);
            remove_comment(line);
            my_cmds = str_tokenizer(line, ";");
            
            for (i = 0; my_cmds[i] != NULL; i++)
            {
                current_cmd = str_tokenizer(my_cmds[i], " ");
                if (current_cmd[0] == NULL)
                {
                    free(current_cmd);
                    break;
                }
                cmd_type = parse_command(current_cmd[0]);
                setup_init(current_cmd, cmd_type);
                free(current_cmd);
            }
            free(my_cmds);
            free(line); // Free the line allocated by my_getline
        }
        exit(status);
    }
}
