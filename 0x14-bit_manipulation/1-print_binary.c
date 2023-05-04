#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */

void print_binary(unsigned long int n)
{
	if (n == 0) {
		putchar('0');
		return;
	}
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if (n & mask)
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
		mask >>= 1;
	}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
	print_binary(0);
	printf("\n");
	print_binary(1);
	printf("\n");
	print_binary(98);
	printf("\n");
	print_binary(1024);
	printf("\n");
	print_binary((1 << 10) + 1);
	printf("\n");
	return (0);
}
