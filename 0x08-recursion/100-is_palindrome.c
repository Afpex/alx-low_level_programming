#include "main.h"

/**
 * _strlen_recursion - size
 * @s: pointer to string parameters
 * Return: recursion
 */

int _strlen_recursion(char *s)
{
	if (!*s)
	{
		return (0);
	}
	return (1 + _strlen_recursion(++s));
}

/**
 * p1 - checks whether a string is a palindrome or not
 * @s: pointer to string
 * @l: length of string
 * Return: 1 if the string is a palindrome, 0 otherwise
 */

int p1(char *s, int l)
{
	if (l < 1)
	{
		return (1);
	}
	if (*s == *(s + l))
	{
		return (p1(s + 1, l - 2));
	}
	return (0);
}

/**
 * is_palindrome - palindrome
 * @s: pointer to string
 * Return: recursion
 */

int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);
		return (p1(s, len - 1));
}
