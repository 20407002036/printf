#include "main.h"
#include <stdarg.h>

void handle_unsignedint(char *output_buffer, int *count, int *buffer_index, va_list args)
{
    int j;
    unsigned int num = va_arg(args, unsigned int);
    char bin_str[BUFF_SIZE];
    int bin_length = 0;

    do
    {
        bin_str[bin_length++] = (num & 1) + '0'; 
        num >>= 1; 
    } while (num > 0);

    for (j = bin_length - 1; j >= 0; j--)
    {
        output_buffer[(*buffer_index)++] = bin_str[j];
        if (*buffer_index == BUFF_SIZE)
        {
            *count += buffer_print(output_buffer, *buffer_index);
            *buffer_index = 0;
        }
    }
}

