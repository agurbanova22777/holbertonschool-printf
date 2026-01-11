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

/**
 * print_int - prints an integer
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
	int n;
	unsigned int num;
	char buf[10];
	int i;
	int count;

	n = va_arg(ap, int);
	count = 0;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	i = 0;
	if (num == 0)
		buf[i++] = '0';

	while (num > 0)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i--)
		count += write(1, &buf[i], 1);

	return (count);
}
