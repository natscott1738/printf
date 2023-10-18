#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int d = va_arg(args, unsigned int);
			int bit;

			for (bit = 1 << (8 * sizeof(unsigned int) - 1); bit > 0; bit >>= 1)
			{
				write(1, (d & bit) ? "1" : "0", 1);
				count++;
			}
			format += 2;
		}
		else
		{

			write(1, format, 1);
			count++;
			format++;
		}
	}
		va_end(args);
		return count;
}
