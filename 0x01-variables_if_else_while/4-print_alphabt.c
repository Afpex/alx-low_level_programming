#include <stdio.h>
/**
 * main - Entrpoint
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char c;

	c = 'a';
	while
		(c <= 'z') {
			if ((c != 'q' && c != 'e') && c <= 'z')
				putchar(c);

			c++;

		}
	putchar('\n');
	return (0);
}
