#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


int handle_format(char formart_char, va_list args);
int buffer_print(char buffer);

/*
* _printf - prints
* @format: pointer to the args
* Description: prints
* Return: int
*/

int _printf(const char *format, ...)
{
/*    int count = 0;*/
int i = 0;
/*
* int ind = 0;
* char *buffer_pri;
*char chars[98];
*/
int length;
va_list args;

va_start(args, format);

length = strlen(format);
/* printf("\n\tLength = %d\n", length);*/
if (args == NULL)
{return (-1);
}

/*printf("length = %d",length);*/


while (i <= (length - 1))
{

if (format[i] == '%')
{
i++;
/*count += */
handle_format(format[i], args);
}
else if (format[i] != '%')
{

buffer_print(format[i]);
}
i++;
}

va_end(args);

return (0);

}

/*
* handle_format - prints
* @formart_char: pointer to the args
* @args: args
 * Description: prints
* Return: int
*/
int handle_format(char formart_char, va_list args)
{
int i, j;
int num = 0;
int temp = num;
int count = 0;
int digit;
int digits;


switch (formart_char)
{
case 'c':
{
buffer_print(va_arg(args, int));
return (0);
break;
}
case 's':

{
const char *str = va_arg(args, const char*);
int count = 0;
while (*str)
{
buffer_print(*str);
str++;
/* count++;*/
}
return (count);
break;
}
case '%':
{
buffer_print('%');
return (1);
}
case 'd':
case 'i':
{
num = va_arg(args, int);
if (num < 0)
{
buffer_print('-');
count++;
num = -num;
}
digits = (num == 0) ? 1 : 0; /*Handle the case of num == 0*/
while (temp > 0)
{
temp /= 10;
digits++;
}

temp = num;
for (i = digits - 1; i >= 0; i--)
{
int divisor = 1;
for (j = 0; j < i; j++)
{
divisor *= 10;
}
digit = temp / divisor;
buffer_print('0' + digit);
count++;
temp -= digit *divisor;
}
break;

}
default:
return (0);
}

return (0);
}

/*
* buffer_print - prints to output
* @buffer: pointer to the args
* Description: priints
* Return: int
*/


int buffer_print(char buffer)
{
return (write(1, &buffer, 1));
}


