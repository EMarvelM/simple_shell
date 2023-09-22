#include "simple_shell.h"

/**
 * allocate_buffer - allocates memory
 * @buf_size: memory size
 * Return: allocated memory address
 */
/* Helper function to allocate a new buffer */
char *allocate_buffer(size_t buf_size)
{
	char *buf = (char *) malloc(buf_size);

	if (buf == NULL)
	{
		errno = ENOMEM;
		return (NULL);   /* out of memory */
	}
	return (buf);
}

/**
 * expand_buffer - increases size of allocated memory
 * @buf_size: memory size
 * @buf: pointer to allocated memory
 * Return: newly allocated memory address
 */
/* Helper function to expand the buffer */
char *expand_buffer(char *buf, size_t buf_size)
{
	char *newBuf = (char *) my_realloc(buf, buf_size);

	buf_size *= 2;   /* double the size of the buffer */
	if (newBuf == NULL)
	{
		errno = ENOMEM;
		return (NULL);   /* out of memory */
	}
	return (newBuf);
}

/**
 * is_empty_line - checks if empty line is passed
 * @len: length of string
 * @buf: pointer to allocated memory
 * Return: newly allocated memory address
 */
int is_empty_line(ssize_t len, char *buf)
{
	return (len == 0 || (len == 1 && buf[0] == '\n'));
}

/**
 * handle_empty_line - handles empty line passed
 * @lineptr: double pointer
 * @buf: pointer to allocated memory
 * Return: -1
 */
int handle_empty_line(char *buf, char **lineptr)
{
	free(buf);
	*lineptr = NULL;
	return (-1);
}

/**
 * terminate_buffer - terminates the buffer
 * @len: length of string
 * @buf: pointer to allocated memory
 */
void terminate_buffer(ssize_t len, char *buf)
{
	buf[len] = '\0';
}

void *my_realloc(void *ptr, size_t size)
{
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		return (malloc(size));
	}
	else
	{
		void *new_ptr = malloc(size);

		if (new_ptr == NULL)
		{
			return (NULL);
		}
		my_memcpy(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *pdest = dest;
	const char *psrc = src;
	size_t i;

	for (i = 0; i < n; i++)
	{
		pdest[i] = psrc[i];
	}
	return (dest);
}