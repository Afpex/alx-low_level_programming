#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation
 * of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int flag = 0;

	mask = ~0UL;
	mask >>= 1;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask)
	{
		if (n & mask)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag)
		{
			_putchar('0');
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
	print_binary((1UL << 10) + 1);
	printf("\n");
	return (0);
}
