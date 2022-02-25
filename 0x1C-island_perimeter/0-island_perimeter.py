#!/usr/bin/python3
"""
Function that returns the perimeter of the island
described in grid
"""


def island_circeter(grid):
    """
    Calculates the perimeter of the island described in grid
    """
    counter = 0
    circ = 0

    while counter < len(grid):
        a = 0
        while a < len(grid[0]):
            if grid[counter][a] == 1:
                circ += 4
                if counter - 1 >= 0 and grid[counter - 1][a] == 1:
                    circ -= 1
                if counter + 1 < len(grid) and grid[counter + 1][a] == 1:
                    circ -= 1
                if a - 1 >= 0 and grid[counter][a - 1] == 1:
                    circ -= 1
                if a + 1 < len(grid[0]) and grid[counter][a + 1] == 1:
                    circ -= 1
            a += 1
        counter += 1
    return circ
