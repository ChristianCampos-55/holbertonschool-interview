#include "sandpiles.h"

/**
 * sandpiles_sum - adds two sandpiles or grids
 * @grid1: grid No1 to add
 * @grid2: grid No2 to add
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_adder(grid1, grid2);
	while (unstable_grid(grid1))
	{
		grid_printer(grid1);
		sand_disperser(grid1, grid2);
	}
}

/**
 * grid_printer - prints grid
 * @grid: grid to be printed
 */

void grid_printer(int grid[3][3])
{
	unsigned int a, b;

	printf("=\n");
	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			if (b)
			{
				printf(" ");
			}
		printf("%d", grid[a][b]);
		}
		printf("\n");
		}
}

/**
 * grid_adder - adds two grids
 * @grid1: grid No1 to add
 * @grid2: grid No2 to add
 */

void grid_adder(int grid1[3][3], int grid2[3][3])
{
	unsigned int a, b;

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			grid1[a][b] += grid2[a][b];
			grid2[a][b] = 0;
		}
	}
}

/**
 * sand_disperser - disperses values throughout the grid
 * @grid1: grid No 1 to disperse
 * @grid2: empty No 2
 */

void sand_disperser(int grid1[3][3], int grid2[3][3])
{
	unsigned int a, b;

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			if (grid1[a][b] > 3)
			{
				if (a > 0)
					grid2[a - 1][b] += 1;
				if (b > 0)
					grid2[a][b - 1] += 1;
				if (a < 2)
					grid2[a + 1][b] += 1;
				if (b < 2)
					grid2[a][b + 1] += 1;
				grid1[a][b] -= 4;
			}
		}
	}
	grid_adder(grid1, grid2);
}

/**
 * unstable_grid - checks if grid is unstable
 * @grid: grid to be checked
 * Return: True if grid is unstable, false if fine
 */

bool unstable_grid(int grid[3][3])
{
	unsigned int a, b;

	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			if (grid[a][b] > 3)
				return (true);
		}
	}
	return (false);
}
