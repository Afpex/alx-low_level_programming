#include "main.h"

/**
 * count_different_bits - counts the number of bits that
 * are different between two numbers
 * @n: first number
 * @m: second number
 *
 * Return: the number of different bits between n and m
 */
unsigned int count_different_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num_different_bits = 0;

	while (n || m)
	{
		if ((n & 1) != (m & 1))
			num_different_bits++;

		n >>= 1;
		m >>= 1;
	}

	return (num_different_bits);
}
