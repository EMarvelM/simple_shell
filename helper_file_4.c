#include "simple_shell.h"
/**
 *_str_spn - gets the length of a prefix substring
 *@str1: the string to be searched
 *@str2: string to be used
 *
 *Return: No. of bytes in initial segment of 5 which are part of a string
 */
int _str_spn(char *str1, char *str2)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int match = 0;
		int i = 0;

		for (i = 0; str1[i] != '\0'; i++)
		{
			if (_strchr(str2, str1[i]) == NULL)
			{
				break;
			}
			match++;
		}
		return (match);
	}
	return (0);
}
