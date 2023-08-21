#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int buffer_print(char buffer);
int handle_character(const char *format, va_list args);

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
        count = handle_character(format, args); 

    va_end(args);
    return (count);
}
/**
* handle_character - changes formart spefiers
* @formart: string to run
* @args: arguments
* Return: int
*/

int handle_character(const char *format, va_list args)
{
    int count = 0;
    const char *ptr = format;

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
            {
                count += buffer_print('%');
            }
            else
            {
                count += buffer_print(*ptr);
            }
            ptr++;
        }
        else
        {
            count += buffer_print(*ptr);
            ptr++;
        }
    }
    return (count);
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




