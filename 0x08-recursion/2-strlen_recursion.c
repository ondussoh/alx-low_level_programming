#include "main.h"
/**
  * _strlen_recursion - returns len of str
  * @s: pointer variable
  * Return: length of string
  */
int _strlen_recursion(char *s)
{
	unsigned int i = 0;

	if (*s)
	{
		i++;
		i = i + _strlen_recursion(s + 1);
	}
	return (i);
}
