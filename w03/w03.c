/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W03
 * Calcuates the value of 2^n for the given n argument.
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

int twoToN(int n);

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Enter a value for n, the power 2 is raised to.\n");
      return 0;
   }

   int result = twoToN(atoi(argv[1]));
   printf("%d", result);
   return 0;
}

int twoToN(int n)
{
   if (n < 1)
   {
      return 1;
   }
   return twoToN(n - 1) + twoToN(n - 1);
}
