#include "sandpiles.h"

/**
 * sum - the sum of two sandpiles
 * @grid1: sandpile
 * @grid2: 2nd sandpile that ends with 0
 */

static void sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
}

/**
 * stabilized - verify if sandpile is stabilized
 * @grid: sandpile
 *
 * Return: 1 if is stable, otherwise return 0
 */

static int stabilized(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - prints the grid
 * @grid: sandpile
 *
 * Return: 1 if is stable, otherwise return 0
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * tear_down - Tears down sandpile
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */

static void tear_down(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid2[i - 1][j]++;
				if (i + 1 < 3)
					grid2[i + 1][j]++;

				if (j - 1 >= 0)
					grid2[i][j - 1]++;
				if (j + 1 < 3)
					grid2[i][j + 1]++;
			}
}

/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);
	while (!stabilized(grid1))
	{
		print_grid(grid1);
		tear_down(grid1, grid2);
		sum(grid1, grid2);
	}
}
