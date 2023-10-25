#!/usr/bin/python3
""" Module for island perimeter"""


def island_perimeter(grid):
    """ Calculate the perimeter of an island """
    perimeter = 0

    # Iterate through rows
    for j in range(len(grid)):
        # Iterate through columns
        for i in range(len(grid[j])):
            # Check if cell is land
            if grid[j][i] == 1:
                # Initial perimeter for a land cell is 4
                perimeter += 4

                # Check neighboring cells, if land reduce perimeter
                if j - 1 >= 0 and grid[j - 1][i] == 1:
                    perimeter -= 1  # Top neighbor
                if i + 1 < len(grid[j]) and grid[j][i + 1] == 1:
                    perimeter -= 1  # Right neighbor
                if i - 1 >= 0 and grid[j][i - 1] == 1:
                    perimeter -= 1  # Left neighbor
                if j + 1 < len(grid) and grid[j + 1][i] == 1:
                    perimeter -= 1  # Bottom neighbor

    return perimeter

