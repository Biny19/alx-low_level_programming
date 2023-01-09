#include <stdlib.h>
#include "main.h"
int word_len(char *s);
int count_words(char *s);
char **strtow(char *str);
/**
 * word_len - Eentry point
 * @s: The string to be searched
 * Return: 0
 */
int word_len(char *s)
{
int i = 0, l = 0;
while (*(s + i) && *(s + i) != ' ')
{
l++;
i++;
}
return (l);
}
/**
* count_word - a function to count the number of words in a string
* @s: string to evaluate
* Return: 0
*/
int count_word(char *s)
{
int i = 0, w = 0, l = 0;
for (i = 0; *(s + i); i++)
l++;
for (i = 0; i < l; i++)
{
if (*(s + i) != ' ')
{
w++;
i += word_len(s + i);
}
}
return (w);
}
/**
* **strtow - splits a string into words
* @str: string to split
* Return: pointer to an array of strings (Success)
* or NULL (Error)
*/
char **strtow(char *str)
{
char **strings;
int i, words, j, letters, c;
if (str == NULL || str[0] == '\0')
return (NULL);
words = count_word(str);
if (words == 0)
return (NULL);
strings = malloc(sizeof(char *) * words);
if (strings == NULL)
return (NULL);
for (j = 0; j <= words; j++)
{
while (str[i] == ' ')
i++;
letters = word_len(str + i);
strings[j] = malloc(sizeof(char) * letters);
if (strings[j] == NULL)
{
for (; j >= 0; j--)
free(strings[j]);
free(strings);
return (NULL);
}
for (c = 0; c < letters; c++)
strings[j][c] = str[i++];
strings[j][c] = '\0';
}
strings[j] = NULL;
return (strings);
}
