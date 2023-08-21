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
const char *ptr = format;

va_list args;
va_start(args, format);


while (*ptr != '\0')
{
if (*ptr == '%')
{
ptr++;
if (*ptr == 's')
{
const char *str = va_arg(args, const char *);
while (*str != '\0')
{
count += buffer_print(*str);
str++;
}
}
else if (*ptr == 'c')
{
char c = va_arg(args, int);
count += buffer_print(c);
}
}
else
{
count += buffer_print(*ptr);
}
ptr++;
}

va_end(args);
return (count);
}






