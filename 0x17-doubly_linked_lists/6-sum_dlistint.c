#include "lists.h"
/**
  * sum_dlistint - calculates the sum of all the data in a listint_t list
  * @head: first node in the linked list
  *
  * Return: resulting sum
  */
int sum_dlistint(dlistint_t *head)
{
int sum;
sum = 0;
if (head != NULL)
{
while (head->prev != NULL)
head = head->prev;
while (head != NULL)
{
sum += head->n;
head = head->next;
}
}
return (sum);
}
