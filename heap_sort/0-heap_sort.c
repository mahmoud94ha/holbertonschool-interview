#include "sort.h"

/**
* swap - Swap two element of an array,
* the one given by the index, and the one after
*
* @array: The array to do some operation
* @idx1: The idx to swap
* @idx2: The idx to swap
*
* Return: Anything, cause void function
*/
void swap(int *array, int idx1, int idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

/**
* reheaping - Re Heaping the heap
*
* @array: The parent array
* @root: The root elem of the heap
* @size: The size of the parent array
* @tmpSize: The size of the heap
*
* Return: Anything, cause void function
*/
void reheaping(int *array, size_t root, size_t size, size_t tmpSize)
{
	size_t idxLeft, idxRight;
	size_t idx;

	while ((root * 2) + 1 <= tmpSize)
	{
		idx = root;
		idxLeft = (idx * 2) + 1;
		idxRight = idxLeft + 1;
		if (idxRight <= tmpSize && array[idxRight] > array[idx])
		{
			if (array[idxRight] > array[idxLeft])
				idx = idxRight;
		}
		if (array[idxLeft] > array[idx])
			idx = idxLeft;
		if (idx == root)
			break;
		swap(array, root, idx);
		print_array(array, size);
		root = idx;
	}
}

/**
* createHeap - Create the heap with an unsorted array
*
* @array: The array to transform into heap
* @size: Size of the array
*
* Return: Anything, cause void function
*/
void createHeap(int *array, size_t size)
{
	int i;

	for (i = size - 2 / 2; i > -1; i--)
	{
		reheaping(array, i, size, size - 1);
		if (i == 0)
			break;
	}
}

/**
* heap_sort - Sort an array using the heap sort
* methode
*
* @array: The array to sort
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void heap_sort(int *array, size_t size)
{

	size_t tmpSize;

	if (!array || size <= 1)
		return;

	createHeap(array, size);

	tmpSize = size - 1;
	while (tmpSize > 0)
	{
		swap(array, 0, tmpSize);
		print_array(array, size);
		tmpSize--;
		reheaping(array, 0, size, tmpSize);
	}
}