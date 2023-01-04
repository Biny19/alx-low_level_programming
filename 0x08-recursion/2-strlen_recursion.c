#include "main.h"
/**
* _strlen_recursion - Entry point
* @s: the string value to be measure
* Return: 0
*/
int _strlen_recursion(char *s)
{
int len = 0;
if (*s)
{
len++;
len += _strlen_recursion(s + 1);
}
return (len);
}
