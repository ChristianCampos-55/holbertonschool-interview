#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2 with *
 * Return: 1 if similar, 0 otherwsie
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	else if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	else if (*s2 == '*')
	{

		if (*(s2 + 1) == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		else if (wildcmp(s1, s2 + 1))
		{
			return (1);
		}
		else
		{
			return (wildcmp(s1 + 1, s2));
		}
	}
	return (0);
}
