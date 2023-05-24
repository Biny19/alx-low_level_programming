#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (List[List[int]]): A rectangular grid representing the island.

    Returns:
        int: The perimeter of the island.

    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                # Check left side
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1

                # Check right side
                if col == cols - 1 or grid[row][col + 1] == 0:
                    perimeter += 1

                # Check top side
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter += 1

                # Check bottom side
                if row == rows - 1 or grid[row + 1][col] == 0:
                    perimeter += 1

    return perimeter
