#include "main.h"
#include <stdarg.h>

/**
* handle_char_spef - string output
* @output_buffer: buffer input
* @count: count track
* @buffer_index: buffer track
* @args: argument list
*/

void handle_char_spef(char *output_buffer, int *count, int *buffer_index, va_list args)
{
    char c = va_arg(args, int);
    output_buffer[(*buffer_index)++] = c;
    if (*buffer_index == BUFF_SIZE)
    {
        *count += buffer_print(output_buffer, *buffer_index);
        *buffer_index = 0;
    }
}