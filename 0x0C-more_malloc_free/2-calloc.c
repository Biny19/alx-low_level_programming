#include <stdlib.h>
#include "main.h"
/**
*_memset - fills memory with a constant byte
* @s: memory area to be filled
* @a: char to copy
* @n: number of times to copy a
*
* Return: pointer to the memory area s
*/
char *_memset(char *s, char a, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
s[i] = a;
}
return (s);
}
/**
*_calloc - allocates memory for an array
* @x: number of elements in the array
* @y: size of each element
*
* Return: pointer to allocated memory
*/
void *_calloc(unsigned int x, unsigned int y)
{
char *p;
if (x == 0 || y == 0)
return (NULL);
p = malloc(y * x);
if (p == NULL)
return (NULL);
_memset(p, 0, x * y);
return (p);
}
