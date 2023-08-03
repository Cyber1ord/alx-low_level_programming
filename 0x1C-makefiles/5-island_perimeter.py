#!/usr/bin/python3

"""Module for island perimeter"""


def island_perimeter(grid):
    """Calculate island perimeter"""
    perimeter_sum = 0

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimeter = 4
                if row - 1 >= 0 and grid[row - 1][col] == 1:
                    perimeter -= 1
                if col + 1 < len(grid[row]) and grid[row][col + 1] == 1:
                    perimeter -= 1
                if col - 1 >= 0 and grid[row][col - 1] == 1:
                    perimeter -= 1
                if row + 1 < len(grid) and grid[row + 1][col] == 1:
                    perimeter -= 1
                perimeter_sum += perimeter

    return perimeter_sum
