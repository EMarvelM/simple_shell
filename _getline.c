#include "simple_shell.h"

#define MAX_LINE_LENGTH 1024

/**
 * _getline - read from the stream
 * @line: buffer to store the string read
 * @len: length of buffer
 * @stream: file ptr stream
 * 
 * Return: -1 on (EOF & erro), > 0 on success
*/
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	char *getline;
	ssize_t read;

	if (*line == NULL || *len == 0)
	{
		*len = 1024;
		*line = malloc(*len);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	getline = _fgets(*line, *len, stream);
	if (getline != NULL)
	{
		read = _strlen(*line);

		if (read > 0 && (*line)[read - 1] == '\n')
		{
			(*line)[read - 1] = '\0';
			read--;
		}
		return (read);
	}
	else
	{
		return (-1);
	}
}

char *_fgets(char *buffer, int max_length, FILE *stream)
{
	int i;
	int c;
	
	if (buffer == NULL || max_length <= 0 || stream == NULL)
	{
		return (NULL);  /* Invalid arguments */
	}
	
	i = 0;

	while (i < max_length - 1)
	{
		c = fgetc(stream);

		if (c == EOF)
		{
			if (i == 0)
			{
				/* No characters read, and we've reached the end of the file */
				return (NULL);
			}
			break;  /* End of line reached */
		}

		buffer[i++] = (char)c;

		if (c == '\n')
		{
			break;  /* End of line reached */
		}
	}

	buffer[i] = '\0';  /* Null-terminate the string */

	return (buffer);
}

size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
