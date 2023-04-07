#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer
 * @b: String representing a binary number
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (b == NULL)
	return (0);

	for (; *b; b++)
	{
	if (*b != '0' && *b != '1')
		return (0);
	n = (n << 1) | (*b - '0');
	}

	return (n);
}
