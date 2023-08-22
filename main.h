#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>

#define BUFF_SIZE  1024

int _printf(const char *format, ...);
int switch_character(const char *format, va_list args);
int buffer_print(const char *buffer, int length);
void handle_string_specifier(char *output_buffer, int *count, int *buffer_index, va_list args);
void handle_char_spef(char *output_buffer, int *count, int *buffer_index, va_list args);
void handle_int_spef(char *output_buffer, int *count, int *buffer_index, va_list args, const char *ptr);
void handle_unsignedint(char *output_buffer, int *count, int *buffer_index, va_list args);


#endif 
