#include "main.h"
#include <stdarg.h>

/**
* handle_character - changes formart spefiers
* @formart: string to run
* @args: arguments
* Return: int
*/
int handle_character(const char *formart, va_list args)
{
int count = 0;
const char *ptr = formart;
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
else if (*ptr == '%')
buffer_print('%');
count +=1;
}
else
{
count += buffer_print(*ptr);
}
ptr++;
}
return (count);
}
