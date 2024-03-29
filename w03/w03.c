/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W03
 *
 * 2^n Brute Force
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

int twoToN(int n);

// Accepts command line argument to raise 2 to the power of.
int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Enter a value for n, the power 2 is raised to.\n");
      return 0;
   }

   int result = twoToN(atoi(argv[1]));
   printf("%d\n", result);
   return 0;
}

// Returns 2^n for the passed value of n.
int twoToN(int n)
{
   if (n < 1)
   {
      return 1;
   }
   return twoToN(n - 1) + twoToN(n - 1);
}
