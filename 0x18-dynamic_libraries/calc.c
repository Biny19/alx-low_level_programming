#include <"calc.h">
/**
 * main - Entry point
 * Return: 0;
 */
int main(void)
{
int num1, num2, result;
result = add(num1, num2);
result = sub(num1, num2);
result = mult(num1, num2);
result = div(num1, num2);
return (0);
}
/**
 * add - Entry point
 * @num1: the first number
 * @num2: the second number
 * Return: 0;
 */
int add(int num1, int num2)
{
return (num1 + num2);
}
/**
 * sub - Entry point
 * @num1: the first number
 * @num2: the second number
 * Return: 0;
 */
int sub(int num1, int num2)
{
return (num1 - num2);
}
/**
 * mult - Entry point
 * @num1: the first number
 * @num2: the second number
 * Return: 0;
 */
int mult(int num1, int num2)
{
return (num1 * num2);
}
/**
 * div - Entry point
 * @num1: the first number
 * @num2: the second number
 * Return: 0;
 */
int div(int num1, int num2)
{
return (num1 / num2);
}
