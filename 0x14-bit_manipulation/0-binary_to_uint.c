#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary
 *
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0, exp = 1;
	int i;

	if (!b)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
		;

	for (i -= 1; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		res += (b[i] - '0') * exp;
		exp *= 2;
	}

	return (res);
}

