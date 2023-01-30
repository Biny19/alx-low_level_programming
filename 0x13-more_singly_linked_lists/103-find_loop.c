#include "lists.h"
/**
  * find_listint_loop - finds the loop in a linked list
  * @head: linked list to search for
  *
  * Return: address of the node where the loop starts, or NULL
  */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *tmp1 = head;
listint_t *tmp2 = head;
if (!head)
return (NULL);
while (tmp1 && tmp2 && tmp2->next)
{
tmp2 = tmp2->next->next;
tmp1 = tmp1->next;
if (tmp2 == tmp1)
{
tmp1 = head;
while (tmp1 != tmp2)
{
tmp1 = tmp1->next;
tmp2 = tmp2->next;
}
return (tmp2);
}
}
return (NULL);
}
