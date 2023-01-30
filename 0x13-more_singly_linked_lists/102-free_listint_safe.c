#include "lists.h"
/**
  * free_listint_safe - frees a linked list
  * @h: pointer to the first node in the linked list
  *
  * Return: number of elements in the freed list
  */
size_t free_listint_safe(listint_t **h)
{
size_t len = 0;
int num;
listint_t *temp;
if (h == NULL || *h == NULL)
return (0);
while (*h)
{
num = *h - (*h)->next;
if (num > 0)
{
temp = (*h)->next;
free(*h);
*h = temp;
len++;
}
else
{
free(*h);
*h = NULL;
len++;
break;
}
}
*h = NULL;
return (len);
}
