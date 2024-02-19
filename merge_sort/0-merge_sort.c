#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *merge - merges two arrays.
 *@arr: main array int.
 *@start: start array int.
 *@mid: mid array int.
 *@end: end array int.
 *@copy: copy int.
 */
void merge(int *arr, int start, int mid, int end, int *copy)
{
	int s = start;
	int m = mid;
	int i = 0;

	for (i = start; i < end; i++)
	{
		if (s < mid && (m >= end || copy[s] < copy[m]))
		{
			arr[i] = copy[s];
			s = s + 1;
		}
		else
		{
			arr[i] = copy[m];
			m = m + 1;
		}
	}
}

/**
 *split - splits the array
 *@arr: array int
 *@first: 1 array to sort int
 *@last: 1st index of the array int
 *@sorted_arr: sorted array int
 */
void split(int *arr, int first, int last, int *sorted_arr)
{
	int mid = (first + last) / 2;
	int i = 0;

	if (last - first <= 1)
		return;

	split(arr, first, mid, sorted_arr);
	split(arr, mid, last, sorted_arr);
	printf("Merging...\n");

	printf("[left]: ");
	for (i = first; i < mid; i++)
	{
		printf("%d", arr[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (i = mid; i < last; i++)
	{
		printf("%d", arr[i]);
		if (i < last - 1)
			printf(", ");
	}
	merge(arr, first, mid, last, sorted_arr);
	printf("\n");
	printf("[Done]: ");
	for (i = first; i < last; i++)
	{
		printf("%d", arr[i]);
		if (i < last - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 *merge_sort - divide and sort the array.
 *@array: array to be sorted int.
 *@size: number of elements in the array size_t.
 */
void merge_sort(int *array, size_t size)
{
	int *cp;
	size_t a = 0;

	cp = malloc(sizeof(int) * size);

	for (a = 0; a < size; a++)
		cp[a] = array[a];
	split(array, 0, size, cp);
	free(cp);
}
