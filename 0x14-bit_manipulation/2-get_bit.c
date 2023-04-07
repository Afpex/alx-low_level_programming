#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to retrieve the bit from
 * @index: the index of the bit to retrieve
 *
 * Return: the value of the bit at index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	for (i = 0; i <= index; i++)
	{
		if (n == 0 && i == index)
			return (0);

		if (i == index)
			return (n & 1);

		n = n >> 1;
	}

	return (-1);
}
