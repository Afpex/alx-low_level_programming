#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 1 if little endian, 0 if big endian
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	return ((*c) ? 1 : 0);
}
