#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @k: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int k, unsigned long int m)
{
	int i, counter = 0;
	unsigned long int current;
	unsigned long int exclusive = k ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			counter++;
	}

	return (counter);
}
