#include "slide_line.h"

/**
 * slide_line - creates the very much addictive 2048 game
 * @line: Pointer to line
 * @size: Size of line (it's an array)
 * @direction: swipe direction
 * Return: 1 or 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int checker, dir;
	size_t finder, replacer, i, halter;

	if (!line)
		return (0);

	dir = direction;

	if (dir != SLIDE_RIGHT && dir != SLIDE_LEFT)
		return (0);

	finder = 0;
	replacer = 0;
	halter = size;
	checker = -1;
	i = 1;

	if (dir == SLIDE_RIGHT)
	{
		finder = size - 1;
		replacer = size - 1;
		i = -1;
		halter = -1;
	}

	while (finder != halter)
	{
		if (*(line + finder) != 0)
		{
			if (checker == *(line + finder))
			{
				*(line + finder) += checker;
				checker = -1;
			}
			else
			{
				checker = *(line + finder);
				if (dir == SLIDE_RIGHT && finder != (size - 1))
                {
                    if (*(line + replacer) != 0)
						replacer += i;
                }
				if (dir == SLIDE_LEFT && finder != 0)
                {
					if (*(line + replacer) != 0)
						replacer += i;
                }
			}
			*(line + replacer) = *(line + finder);
			if (replacer != finder)
				*(line + finder) = 0;
		}
		finder += i;
	}
	return (1);
}
