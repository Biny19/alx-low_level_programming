#include <stdio.h>

int main(void)
{
int n;
int a[5];
int *p;
<<<<<<< HEAD

=======
  
>>>>>>> b0281a8720206f860ac3c217ed785798f5fa88d7
a[2] = 1024;
p = &n;
/*
* write your line of code here...
* Remember:
* - you are not allowed to use a
* - you are not allowed to modify p
* - only one statement
* - you are not allowed to code anything else than this line of code
*/
<<<<<<< HEAD
*(p + 5) =98;
=======
  *(p + 5) = 98;
>>>>>>> b0281a8720206f860ac3c217ed785798f5fa88d7
/* ...so that this prints 98\n */
printf("a[2] = %d\n", a[2]);
return (0);
}
