#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int r, c;
	int counter = pow(3, level);

	for (r = 0; r < counter; r++)
	{
		for (c = 0; c < counter; c++)
		{
			printer(r, c);
		}
		printf("%c", '\n');
	}
}

/**
 * printer - function that prints the menger sponge
 * @r: rows to print
 * @c: columns to print
 */
void printer(int r, int c)
{
	char simb = '#';

	while (r || c)
	{
		if (r % 3 == 1 && c % 3 == 1)
			simb = ' ';
		r = r / 3;
		c = c / 3;
	}
	printf("%c", simb);
}
