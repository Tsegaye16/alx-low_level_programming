#include "search_algos.h"

/**
  * _binary_search - a function that searches for a value in a sorted
  *	array of integers using the Exponential search algorithm
  *
  * @array: is a pointer to the first element of the array to search in.
  * @left: The starting index of the sub array to search.
  * @right: The ending index of the sub array to search.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t k;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (k = left; k < right; k++)
			printf("%d, ", array[k]);
		printf("%d\n", array[k]);

		k = left + (right - left) / 2;
		if (array[k] == value)
			return (k);
		if (array[k] > value)
			right = k - 1;
		else
			left = k + 1;
	}

	return (-1);
}

/**
  * exponential_search - the function to search a value in a sorted array
  *	of integers using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t k = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (k = 1; k < size && array[k] <= value; k = k * 2)
			printf("Value checked array[%ld] = [%d]\n", k, array[k]);
	}

	right = k < size ? k : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", k / 2, right);
	return (_binary_search(array, k / 2, right, value));
}
