#include "main.h"

/**
 * clear_bit - function changes the value of a specified bit to 0
 * @n: A pointer that refers to the number to be modified.
 * @index: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

