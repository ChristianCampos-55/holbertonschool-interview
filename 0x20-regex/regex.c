#include "regex.h"

/**
 * regex_match - at checks whether a given pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression
 * Return:  1 if the pattern matches the string, or 0 if it doesn’t
 */

int regex_match(char const *str, char const *pattern)
{
	int holder = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			holder = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || holder);
	}
	return (0);
}
