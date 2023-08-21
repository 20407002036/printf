#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>

int _printf(const char *format, ...);
int buffer_print(char buffer);
int handle_character(const char *formart, va_list args);

#endif 