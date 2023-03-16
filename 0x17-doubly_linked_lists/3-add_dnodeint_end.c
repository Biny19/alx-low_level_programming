#include "lists.h"
/**
  * add_dnodeint_end - adds a node at the end of a linked list
  * @head: pointer to the first element in the list
  * @n: data to insert in the new element
  *
  * Return: pointer to the new node, or NULL if it fails
  */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *h;
dlistint_t *new;
new = malloc(sizeof(dlistint_t));
if (new == NULL)
return (NULL);
new->n = n;
new->next = NULL;
h = *head;
if (h != NULL)
{
while (h->next != NULL)
h = h->next;
h->next = new;
}
else
{
*head = new;
}
new->prev = h;
return (new);
}
