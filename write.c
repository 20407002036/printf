#include "main.h"
#include <unistd.h>

/**
* buffer_print - print buffer
* @buffer: string buffer
* @length: lenght of buffer
* Return: write to stdout
*/

int buffer_print(const char *buffer, int length)
{
    return write(1, buffer, length);
}