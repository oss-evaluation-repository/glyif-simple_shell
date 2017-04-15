#include "header.h"

/**
 * _strncat - concatenates from src string to dest string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to concatenate
 *
 * Return: pointer to destination
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares string
 * @s1: first string
 * @s2: second string
 *
 * Return: difference between two ascii valuves
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;

	while (1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		if (s1[i] == '\0' || s2[i] == '\0')
			break;

		i++;
	}

	return (0);
}

/**
 * _strlen - finds and returns length of string
 * @str: string to find length
 *
 * Return: length of string
 */
unsigned int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - takes a string and copies to another a new memory location
 * @str: string to copy
 *
 * Return: pointer to copied string
 */
char *_strdup(char *str)
{
	unsigned int len, j;
	char *ptrstring;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	ptrstring = safe_malloc((len + 1) * sizeof(char));

	for (j = 0; j < len; j++)
		ptrstring[j] = str[j];
	ptrstring[j] = '\0';

	return (ptrstring);
}

/**
 * sp_strncmp - checks if 2 strings are of equal value and length
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: difference of first characters that are of diff value or 0 on success
 */
int sp_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		if (s1[j] != s2[j])
			return (s1[j] - s2[j]);

	return (0);
}

/**
 * _strcpy - copies a string from src to dest
 * @dest: new copy of string
 * @src: the source of the copy
 *
 * Return: pointer to copy
 */
char *_strcpy(char *dest, char *src)
{
	int c;

	for (c = 0; src[c] != '\0'; c++)
		dest[c] = src[c];

	dest[c] = '\0';

	return (dest);
}

/**
 * _strncpy - copies string from source to destination
 * @dest: destination string
 * @src: source string to be copied
 * @n: bytes to be copied from source string
 *
 * Return: destination string concatenated
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[j] = src[j];

	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}

/**
 * _strcat - concatenates from src string to dest string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination
 */
char *_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;

	while (*src)
		*(dest++) = *(src++);

	*dest = '\0';

	return (dest);
}

/**
 * int_to_str - convert an integer to a string
 * @n: unsigned integer to print
 * Return: string with converted integer
 */
char *int_to_str(unsigned int n)
{
	unsigned int copy, size;
	int nth, chars_written;
	char *str;
	int  chars;

	size = 1;
	chars_written = 0;
	copy = n;

	if (n < 10)
	{
		str = safe_malloc(2);
		str[0] = ('0' + n);
		return (str);
	}

	chars = 0;
	while (copy / 10 != 0)
	{
		copy /= 10, size *= 10;
		chars++;
	}

	str = safe_malloc(chars + 1);
	while (size > 0)
	{
		nth = n / size;
		str[chars_written] = ('0' + nth);
		n -= nth * size;
		size /= 10;
		chars_written++;
	}
	str[chars_written] = '\0';
	return (str);
}

/**
 * str_replace - replaces part of a string for another
 * @string: string to replace
 * @start: where to start
 * @end: where to end
 * @rep: string to replace with
 *
 * Return: replaced string
 */
char *_str_replace(char *string, unsigned int start, unsigned int end, char *rep)
{
	char *new_str;

	new_str = safe_malloc(_strlen(string) + _strlen(rep) + 1);

	_strncpy(new_str, string, start);

	_strcat(new_str, rep);

	if (end < _strlen(string) - 1)
		_strcat(new_str, &string[end + 1]);

	return (new_str);
}
