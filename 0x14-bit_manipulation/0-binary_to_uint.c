#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary
 *
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res;
	int i, exp;

	if (!b)
		return (0);

	res = 0;

	for (i = 0; b[i] != '\0'; i++)
		;

	for (exp = 1; i >= 0; exp *= 2;  i--)
	{
		if (b[i] != '0' && b[i] != '1')
		{
		return (0);
		}

		if (b[i] & 1)
		{
			res += exp;
		}

	return (res);
}
