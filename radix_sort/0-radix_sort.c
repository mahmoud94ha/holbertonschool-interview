#include "sort.h"

/**
 *get_max - maximum element from an array
 *@array: the maximum element
 *@size: elements in the array
 *Return: maximum ele
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 *radix_sort - Sorts an array of integers
 *@array: array to be sorted
 *@size: Number of ele
 */
void radix_sort(int *array, size_t size)
{
	int *out;
	int max, nma;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	out = malloc(sizeof(int) * size);
	if (out == NULL)
		return;

	for (nma = 1; max / nma > 0; nma *= 10)
	{
		int count[10] = { 0 };

		size_t i;

		for (i = 0; i < size; i++)
			count[(array[i] / nma) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i < SIZE_MAX; i--)
		{
			out[count[(array[i] / nma) % 10] - 1] = array[i];
			if (i == 0)
				break;
			count[(array[i] / nma) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = out[i];

		print_array(array, size);
	}

	free(out);
}
