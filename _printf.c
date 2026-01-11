#include "main.h"
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i;
	int count;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	i = 0;
	count = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				count += write(1, "%", 1);
				break;
			}

			i++;
			if (format[i] == 'c')
				count += print_char(ap);
			else if (format[i] == 's')
				count += print_string(ap);
			else if (format[i] == '%')
				count += write(1, "%", 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}

	va_end(ap);
	return (count);
}
