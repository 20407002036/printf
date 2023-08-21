#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
* _printf - imitates the simple actions of printf
* @format: pointer to the string to be printed
* Return: int
*/

int _printf(const char *format, ...)
{
int count = 0;

va_list args;
va_start(args, format);

if (format == NULL)
return (-1);
else
handle_character(format, args);

va_end(args);
return (count);
}






