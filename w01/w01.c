/*
 * Name: Austin Kugler
 * Assignment: W01
 * Simple functionality for calculating the minimum distance betweeen
 * any two elements in an array.
*/
#include <stdio.h>
#include <stdlib.h>

int MinDistance(int size, int arr[]);

/*
 * Accepts command line arguments as elements of an array.
 */
int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("Enter at least two elements, separated by spaces.\n");
      return 0;
   }
   int arr[argc - 1];
   for (int i = 1; i < argc; ++i)
   {
      arr[i - 1] = atoi(argv[i]);
   }
   int dmin = MinDistance(argc - 1, arr);
   printf("%d\n", dmin);
   return 0;
}

/*
 * Returns the minimum distance between any two elements in an array.
 */
int MinDistance(int size, int arr[])
{
   int dmin = abs(arr[0] - arr[1]);
   for (int i = 0; i < size; ++i)
   {
      for (int j = 0; j < size; ++j)
      {
         int diff = abs(arr[i] - arr[j]);
         if (i != j && diff < dmin)
         {
            dmin = diff;
         }
      }
   }
   return dmin;
}
