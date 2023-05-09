#include "main.h"

/**
 * get_bit - Returns the bit value of a decimal number at a specified index
 * @n: number to lookfor
 * @index: The position of the bit in the number's binary representation.
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}

