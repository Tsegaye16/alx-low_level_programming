#include "search_algos.h"

/**
 * interpolation_search - The function used to search a value in an array of
 *	integers using the Interpolation search algorithm
 *
 * @array: input array
 * @size: array size
 * @value: value to search
 * Return: index of the number
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t index, low, high;
	double f;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;

	while (size)
	{
		f = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
		index = (size_t)(low + f);
		printf("Value checked array[%d]", (int)index);

		if (index >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[index]);
		}

		if (array[index] == value)
			return ((int)index);

		if (array[index] < value)
			low = index + 1;
		else
			high = index - 1;

		if (low == high)
			break;
	}

	return (-1);
}
