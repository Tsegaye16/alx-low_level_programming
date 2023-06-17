#include "main.h"
/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @k: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int k, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (k >> index) & 1;

	return (bit_value);
}
