#include "lists.h"
/**
* delete_dnodeint_at_index - deletes a node
* in a dlinked list at a certain index
* @head: pointer to the first element in the list
* @index: index of the node to delete
*
* Return: 1 (Success), or -1 (Fail)
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp;
dlistint_t *current;
unsigned int i;
temp = *head;
if (temp != NULL)
while (temp->prev != NULL)
temp = temp->prev;
i = 0;
while (temp != NULL)
{
if (i == index)
{
if (i == 0)
{
*head = temp->next;
if (*head != NULL)
(*head)->prev = NULL;
}
else
{
current->next = temp->next;
if (temp->next != NULL)
h1->next->prev = current;
}
free(temp);
return (1);
}
current = temp;
temp = temp->next;
i++;
}
return (-1);
}
