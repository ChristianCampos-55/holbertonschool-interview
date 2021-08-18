#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void grid_adder(int grid1[3][3], int grid2[3][3]);
bool unstable_grid(int grid[3][3]);
void sand_disperser(int grid1[3][3], int grid2[3][3]);
void grid_printer(int grid[3][3]);

#endif /* SANDPILES_H */
