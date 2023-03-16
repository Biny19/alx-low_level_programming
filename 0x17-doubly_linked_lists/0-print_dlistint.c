#include "lists.h"
/**
  * print_dlistint - prints all the elements of a linked list
  * @h: linked list of type listint_t to print
  *
  * Return: number of nodes
  */
size_t print_dlistint(const dlistint_t *h)
{
size_t i = 0;
while (h)
{
printf("%d\n", h->n);
i++;
h = h->next;
}
return (i);
}
