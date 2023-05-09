#include "main.h"

/**
 * set_bit - a function that changes the value of a bit to 1 at the specified index
 * @n: A pointer that references the number to be modified.
 * @index: The position of the bit that needs to be changed to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
