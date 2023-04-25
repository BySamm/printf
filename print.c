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
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);

						printf("%d", num);
						count += num_digits(num);
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


/**
 * num_digits - Function to check for digits
 * @num: The passed in arg
 * Return: Counter
 */

int num_digits(int num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
