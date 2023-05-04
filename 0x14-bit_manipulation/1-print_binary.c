#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if (n & mask)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask >>= 1;
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	unsigned long int num = 42;

	printf("Binary representation of %lu: ", num);
	print_binary(num);
	printf("\n");
	return (0);
}
