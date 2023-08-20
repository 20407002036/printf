#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


int handle_format(char formart_char, va_list args);
int buffer_print(char buffer);
/**
 * _printf - imitates the simple actions of printf
 * @format: pointer to the string to be printed
 * Return: int
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int i = 0;
	int ind = 0;
	char *buffer_pri;
	int length;

	va_list args;

	va_start(args, format);

	length = strlen(format);
	if (args == NULL)
	{return (-1);
	}
	while (i <= length)
	{
		if (format[i] != '%')
		{


			buffer_print(format[i]);
			i++;
		}
		else if (format[i] == '%')
		{
			format[++i];
			count += handle_format(format[i], args);
		}
	}

	va_end(args);

	return (0);

}
/**
 * handle_format - handles the printing of fomart specifiers
 * @formart_char: char to determine data type
 * @args: arguements
 * Return: int
 */
int handle_format(char formart_char, va_list args)
{
	int count = 0;

	switch (formart_char)
	{
		case 'c':
			{
				buffer_print(va_arg(args, int));
				return (0);
			}
		case 's':

			{
				const char *str = va_arg(args, const char*);
				int count = 0;

				while (*str)
				{
					buffer_print(*str);
					str++;
					count++;
				}
				return (count);
			}
		case '%':
			{
				buffer_print('%');
				return (1);
			}
		case 'd':
		case 'i':
			{
				int num = va_arg(args, int);

				if (num < 0)
				{
					buffer_print('-');
					count++;
					num = -num;
				}
				int temp = num;
				int digits = (num == 0) ? 1 : 0;

				while (temp > 0)
				{
					temp /= 10;
					digits++;
				}

				temp = num;
				for (int i = digits - 1; i >= 0; i--)
				{
					int divisor = 1;

					for (int j = 0; j < i; j++)
					{
						divisor *= 10;
					}
					int digit = temp / divisor;

					buffer_print('0' + digit);
					count++;
					temp -= digit * divisor;
				}
				break;

			}
		default:
			return (0);
	}
}
/**
 * buffer_print - prints the contents of the string
 * @buffer: char to be printed
 * Return: int
 */
int buffer_print(char buffer)
{
	return (write(1, &buffer, 1));
}

