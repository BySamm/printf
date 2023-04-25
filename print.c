#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Function to print passed args in different conversions
 * @format: Different formats
 * Return: The passed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c, *s;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						c = va_arg(args, int);
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						s = va_arg(args, char *);

						while (*s != '\0')
						{
							putchar(*s);
							s++;
							count++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
				default:
					{
						printf("Error: unknown conv. '%%%c'", *format);
					}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

