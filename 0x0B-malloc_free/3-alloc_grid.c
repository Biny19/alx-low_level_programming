#include "main.h"
#include <stdlib.h>
/**
* alloc_grid - Entry point
* @width: width input
* @height: height input
* Return: pointer to 2 dim. array
*/
int **alloc_grid(int width, int height)
{
int **str;
int i, j;
if (width <= 0 || height <= 0)
return (NULL);
str = malloc(sizeof(int *) * height);
if (str == NULL)
return (NULL);
for (i = 0; i < height; i++)
{
str[i] = malloc(sizeof(int) * width);
if (str[i] == NULL)
{
for (; i >= 0; i--)
free(str[i]);
free(str);
return (NULL);
}
}
for (i = 0; i < height; i++)
{
for (j = 0; j < width; j++)
str[i][j] = 0;
}
return (str);
}
