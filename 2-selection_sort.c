#include "sort.h"

/**
 * swap_ints - Swaps two integers in array
 * @y: first integer to be swapped
 * @x: second integer to be swapped
 */
void swap_ints(int *y, int *x)
{
	int tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

/**
 * selection_sort - Sort arrays of integers in ascending order
 * @array: array of integers
 * @size: array size
 * Description: this prints arrays after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
