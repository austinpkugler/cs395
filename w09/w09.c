/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W09
 *
 * Implementation of selection sort.
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int array[], int size);
void swap(int *a, int *b);
void selectionSort(int array[], int size);

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

   selectionSort(array, argc - 1);

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

// Swaps two elements.
void swap(int *a, int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

// Sorts an array of integers using selection sort.
void selectionSort(int array[], int size)
{
   printArray(array, size);

   int i, j;
   for (i = 0; i < size - 1; i++)
   {
      int minIndex = i;
      for (j = i + 1; j < size; j++)
      {
         if (array[j] < array[minIndex])
         {
            minIndex = j;
         }
      }

      swap(&array[minIndex], &array[i]);
      printArray(array, size);
   }
}