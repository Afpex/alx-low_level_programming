#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int num = 1;
	char *endian_ptr = (char *)&num;

	if (*endian_ptr == 1)
	return (1);
	else
	return (0);
