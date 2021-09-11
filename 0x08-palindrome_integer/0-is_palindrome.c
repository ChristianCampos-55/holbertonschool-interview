#include "palindrome.h"

/**
 * is_palindrome - checks if integer is palindrome
 * @n: ulong to check
 * Return: 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{

	unsigned long checker = 0;
	unsigned long h = n;

	while (h != 0)
	{
		checker += h % 10;
		h /= 10;
		if (h != 0)
			checker *= 10;
	}
	if (checker == n)
		return (1);
	return (0);

}
