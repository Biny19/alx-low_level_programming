#include <stdlib.h>
#include <time.h>
#include<stdio.h>
/* more headers goes there */
/* betty style doc for function main goes there */
/*
 *main -Entry point
 *
 * Return: Always 0 (Success)
 */
/**
 * main -prints "is positive" if variable n greater than zero
 * main -prints "is zero" if variable n is zero
 * main -prints"is negative" if variable n less than zero
 */
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
/* your code goes there */
if (n > 0)
{
printf("%d is positive\n", n);
}
else if (n == 0)
{
printf("%d is zero\n", n);
}
else
{
printf("%d is negative\n", n);
}
return (0);
}
