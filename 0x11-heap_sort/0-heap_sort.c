 #include "sort.h"

/**
 * swap - swap the array position
 * @first: pointer to first position
 * @second: pointer to second position
 */

void swap(int *first, int *second)
{
	*first ^= *second, *second ^= *first, *first ^= *second;
}

/**
 * sift_down - move value
 * @array: array that represents binary tree
 * @size: size of the array
 * @n: size of array portion that is still unsorted
 * @i: node to sift-down
 */

void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t max, l, r;

	do {
		max = i;
		l = 2 * i + 1;
		r = 2 * i + 2;
		if (l < n && array[l] > array[max])
			max = l;
		if (r < n && array[r] > array[max])
			max = r;
		if (max != i)
		{
			swap(array + i, array + max);
			print_array(array, size);
			i = max, max = 0;
		}
	} while (max != i);
}

/**
 * heap_sort - heapify and then heap sorts an array
 * @array: array to heap sort
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || !size)
		return;
	for (i = size / 2 - 1; i > -1; --i)
		sift_down(array, size, size, i);
	for (i = size - 1; i > 0; --i)
	{
		swap(array, array + i);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
