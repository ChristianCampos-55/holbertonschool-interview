#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds all the possible substrings on a list of words
 * @s: string to scan
 * @words: array of substring
 * @nb_words:  number of elements in the array words
 * @n:  address at which to store the number of elements in the returned array
 * Return: an allocated array, storing each index in s
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *m = NULL;
	char *holder = NULL, *p = NULL;
	int length, diclxd = 0, countcula = 0, regularl, i, j, k;

	length = strlen(s);
	regularl = strlen(words[0]);
	diclxd = regularl * nb_words;
	holder = calloc((diclxd + 1), sizeof(char));
	m = calloc((length + 1), sizeof(char));

	for (i = 0; i <= length - diclxd;)
	{
		strncpy(holder, &s[i], diclxd);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < diclxd;)
			{
				p = strstr(holder + k, words[j]);
				if (p != NULL && ((p - holder) % regularl) == 0)
					break;
				else if (p != NULL)
				{
					k = p - holder + 1;
					p = NULL;
				}
				else if (p == NULL)
					goto nextseg;
			}
			if (p != NULL)
				memset(p, '.', regularl);
			else
				goto nextseg;
		}
		if (length != 0 && diclxd != 0)
			m[countcula++] = i;
nextseg:
		i++;
	}
	free(holder);
	*n = countcula;
	return (m);
}
