/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W02
 * Simple functionality for calculating the minimum distance betweeen
 * any two elements in an array, with improved efficiency.
 *********************************************/
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
      printf("Enter at least two elements.\n");
      return 0;
   }
   int arr[argc - 1];
   int i;
   for (i = 1; i < argc; ++i)
   {
      arr[i - 1] = atoi(argv[i]);
   }
   int dmin = MinDistance(argc - 1, arr);
   printf("dmin: %d\n", dmin);
   return 0;
}

/*
 * Returns 0 if two passed elements are equal, <0 if the first is lower,
 * and >0 if the first is higher.
 */
int compare(const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

/*
 * Returns the minimum distance between any two elements in an array.
 */
int MinDistance(int size, int arr[])
{
   // Sort the elements for efficient searching
   qsort(arr, size, sizeof(int), compare);

   // Start by comparing the first and second element.
   int dmin = abs(arr[0] - arr[1]);

   // Check each subsequent elements for a lower distance.
   int i;
   for (i = 1; i < size - 1; ++i)
   {
      // Find difference between current element and next element.
      int diff = abs(arr[i] - arr[i + 1]);

      // If the difference is lower, a new min distance has been found.
      if (diff < dmin)
      {
         dmin = diff;
      }
   }

   // Return the final min distance.
   return dmin;
}
