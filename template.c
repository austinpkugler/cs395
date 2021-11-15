/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W__
 *
 * Summary
 *********************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void printArray(int array[], int size);
void swap(int *a, int *b);

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("Enter integer elements of an array separated by spaces.\n");
      return 0;
   }

   int array[argc - 1];
   int i;
   for (i = 1; i < argc; i++)
   {
      array[i - 1] = atoi(argv[i]);
   }
   return 0;
}

// Prints the elements of an array.
void printArray(int array[], int size)
{
   int i;
   for (i = 0; i < size; i++)
   {
      printf("%d ", array[i]);
   }
   printf("\n");
}

// Swaps two elements of an array with each other.
void swap(int *a, int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}
