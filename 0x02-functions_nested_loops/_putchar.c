#include <unistd.h>
/**
 * _putchar - writes the character c to studout
 * *@c: The character to print
 * Return: On succecc 1.
 * On error, -1 is returned, and errno set appropiately
 */
int _putchar(char c)
{
	return (write(1,&c,1));
}
