#include "main.h"
#include <stdarg.h>

void handle_int_spef(char *output_buffer, int *count, int *buffer_index, va_list args, const char *ptr) 
{
    int i = 0;
    int num = va_arg(args, int);
    char num_str[BUFF_SIZE];
    int num_length = 0;
                
    int is_negative = 0;
    if (num < 0 && (*ptr == 'd' || *ptr == 'i')) 
    {
        is_negative = 1;
        num = -num;
    }

    if (num == 0) {
        num_str[num_length++] = '0';
    } else 
    {
        while (num > 0) {
            int digit = num % 10;
            num_str[num_length++] = '0' + digit;
            num /= 10;
        }
    }

    if (is_negative) 
    {
        num_str[num_length++] = '-';
    }

    for (i = num_length - 1; i >= 0; i--) {
        output_buffer[(*buffer_index)++] = num_str[i];
        if (*buffer_index == BUFF_SIZE) 
        {
            *count += buffer_print(output_buffer, *buffer_index);
            *buffer_index = 0;
        }
    }
}
