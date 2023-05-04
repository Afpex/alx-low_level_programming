#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int bitCount = 0;

	while ((mask << 1) <= n)
	{
		mask <<= 1;
		bitCount++;
	}

	for (; bitCount >= 0; bitCount--)
	{
		putchar((n & mask) ? '1' : '0');
		mask >>= 1;
	}
}
