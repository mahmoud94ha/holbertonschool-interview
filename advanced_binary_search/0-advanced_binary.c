#include "search_algos.h"

/**
* print_array - Print an array according to the start and end pointer
*
* @array: The array to search in
* @start: Pointer to the first index of the current subarray
* @end: Pointer to the last index of the current subarray
*
* Return: Anything, cause void function
*/
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	if (!array)
		return;
	printf("Searching in array:");
	for (i = start; i < end; i++)
		printf(" %d,", array[i]);
	printf(" %d\n", array[i]);
}

/**
* binary_search_rec - Search algo using binary search time complexity
*
* @array: The array to search in
* @start: Pointer to the first index of the current subarray
* @end: Pointer to the last index of the current subarray
* @value: The value to find
*
* Return: The index of the founded value, -1 if any issues
*/
int binary_search_rec(int *array, size_t start, size_t end, int value)
{
	int middle;

	if (start > end)
		return (-1);
	print_array(array, start, end);
	middle = (start + end) / 2;
	if (value == array[middle] && middle - 1 >= 0
					&& array[middle - 1] == array[middle])
		return (binary_search_rec(array, start, middle, value));
	if (value == array[middle])
		return (middle);
	if (value < array[middle])
		return (binary_search_rec(array, start, middle, value));
	return (binary_search_rec(array, middle + 1, end, value));
}

/**
* advanced_binary - Search a value using an advanced
*                            method of the binary search
*
* @array: The array to search in
* @size: The size of the array
* @value: The value to find
*
* Return: The index of the founded value, -1 if any issues
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_search_rec(array, 0, size - 1, value));
}
