#include "lists.h"
/**
  * free_listint - frees a linked list
  * @head: listint_t list to be freed
  */
void free_dlistint(dlistint_t *head)
{
dlistint_t *tmp;
if (head != NULL)
while (head->prev != NULL)
head = head->prev;
while ((tmp = head) != NULL)
{
head = head->next;
free(tmp);
}
}
