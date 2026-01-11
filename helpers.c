#include "main.h"
#include <unistd.h>

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
