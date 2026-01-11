#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a character
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list ap)
{
	char *s;
	int len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";

	len = 0;
	while (s[len])
		len++;

	return (write(1, s, len));
}
