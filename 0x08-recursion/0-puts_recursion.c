#include "main.h"
/**
  * _puts_recursion - prints characters in string followed by new line
  * @s: pointer variable
  * Return: Alwasys 0 success
  */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
	{ _putchar(10);
	}
}
