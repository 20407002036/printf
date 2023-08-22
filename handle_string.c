#include "main.h"
#include <stdarg.h>

void handle_string_specifier(char *output_buffer, int *count, int *buffer_index, va_list args) {
    const char *str = va_arg(args,const char *);
    while (*str != '\0') {
        output_buffer[*buffer_index] = *str;
        (*buffer_index)++;
        if (*buffer_index == BUFF_SIZE) {
            *count += buffer_print(output_buffer, BUFF_SIZE);
            *buffer_index = 0;
        }
        str++;
    }
}

