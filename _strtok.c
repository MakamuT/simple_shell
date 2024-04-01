#include "main.h"
#include <stddef.h>
/**
 * _strchr - locates the first occurrence of the character c
 * @str: string to be searched
 * @c: char to be matched
 * Return: pointer to the located character or NULL if not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return ((*str == '\0' && c == '\0') ? (char *)str : NULL);
}

/**
 * _strspn - spans a string
 * @str: string
 * @sset: string occurrence to be searched
 * Return: number of characters spanned
 */
size_t _strspn(const char *str, const char *sset)
{
	size_t count = 0;

	while (*str && _strchr(sset, *str))
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * _strcspn - spans the complement of a string
 * @str: string
 * @sset: string occurrence to be searched
 * Return: number of characters spanned
 */
size_t _strcspn(const char *str, const char *sset)
{
	size_t count = 0;

	while (*str && !_strchr(sset, *str))
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * _strtok - isolates sequential tokens in a NUL-terminated string
 * @str: string
 * @delim: delimiters
 * Return: pointer to the beginning of each subsequent token in the string
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *tokenEnd;

	if (str == NULL && lastToken != NULL)
		str = lastToken;
	if (str == NULL || *str == '\0')
		return (NULL);
	str += _strspn(str, delim);
	if (*str == '\0')
		return (NULL);
	tokenEnd = str + _strcspn(str, delim);
	if (*tokenEnd != '\0')
	{
		*tokenEnd = '\0';
		lastToken = tokenEnd + 1;
	}
	else
		lastToken = NULL;
	return (str);
}
