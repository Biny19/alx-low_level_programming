#include "main.h"
/**
* _abs - Entry point
* @n: The character to print
* Return: 0
*/
int _abs(int n)
{
if (n < 0)
{
return (n * (-1));
}
else if (n == 0)
{
return (0);
}
else
{
return (n);
}
}
