#include "sort.h"

/**
 * swap_ints - this swaps two integers in array
 * @y: first integer to to be swapped
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
 * bubble_sort - this sorts array of integers in ascending order
 * @array: array of integers to be sorted
 * @size: size of array
 * Description: This prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
