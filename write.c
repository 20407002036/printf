#include "main.h"
#include <unistd.h>

/**
* buffer_print - prints the contents of the string
* @buffer: char to be printed
* Return: int
*/
int buffer_print(char buffer)
{
return (write(1, &buffer, 1));
}
