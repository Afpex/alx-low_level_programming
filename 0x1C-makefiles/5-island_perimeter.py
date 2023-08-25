#!/usr/bin/python3
    """Defines an island perimeter measuring function."""

def island_perimeter(grid):
    """Returns the perimeter of an island described in grid
    """
    perimeter = 0
    width = len(grid)
    height = len(grid[0])

    for i in range(width):
        for j in range(height):
            if grid[i][j] == 1:
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1
                if i == width - 1 or grid[i+1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1
                if j == height - 1 or grid[i][j+1] == 0:
                    perimeter += 1

return perimeter
