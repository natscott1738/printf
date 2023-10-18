#include <stdio.h>
#include "main.h"
#include <stdarg.h>

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
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%' || *(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			char c;
			char *s;
			int d;

			switch (*(format + 1))
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s)
					{
						write(1, s, 1);
						s++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					if (d < 0)
					{
						write(1, "-", 1);
						count++;
						d = -d;
					}
					char buffer[11];
					int len = 0;
					do
					{
						buffer[len++] = '0' + d % 10;
						d /= 10;
					}
					while (len > 0)
					{
						write(1, &buffer[--len], 1);
						count++;
					}
					break;
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

int main(void)
{
	int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Length:[%d]\n", len);
	len = _printf("Character:[%c]\n", 'H');
	printf("Length:[%d]\n", len);
	len = _printf("String:[%s]\n", "I am a string !");
	printf("Length:[%d]\n", len);
	len = _printf("Percent:[%%]\n");
	printf("Length:[%d]\n", len);
	len = _printf("Negative:[%d]\n", -762534);
	printf("Length:[%d]\n", len);
	return 0;
}
