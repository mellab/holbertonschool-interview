#include "search_algos.h"

/**
 * printer - Prints an array
 * @array: Target array
 * @left: Left index of @array
 * @right: Right index of @array
 */
void printer(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i == right)
			printf("\n");
		else
			printf(", ");
	}
}


/**
 * binary_search_rec - Binary search
 * @array: Target array
 * @start: Start of the @array
 * @end: End of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int binary_search_rec(int *array, size_t start, size_t end,  int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	mid = (end + start) / 2;
	printer(array, start, end);
	if (array[mid] == value && array[mid - 1] != value)
	{
		return (mid);
	}
	if (array[mid] < value)
	{
		return (binary_search_rec(array, mid + 1, end,  value));
	}
	else
		return (binary_search_rec(array, start, mid, value));
}

/**
 * advanced_binary - Advanced binary search
 * @array: Target array
 * @size: Size of @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (binary_search_rec(array, 0, size - 1, value));
}
