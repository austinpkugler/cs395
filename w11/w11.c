/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W11
 *
 * Insertion Sort
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int array[], int size, int progress);
void swap(int *a, int *b);
void insertionSort(int array[], int size);

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

   insertionSort(array, argc - 1);

   return 0;
}

// Prints the elements of an array.
void printArray(int array[], int size, int progress)
{
   int i;
   for (i = 0; i < size; i++)
   {
      printf("%d ", array[i]);
      if (i == progress)
      {
         printf("| ");
      }
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

// Sorts an array of integers using insertion sort.
void insertionSort(int array[], int size)
{
   printArray(array, size, 0);

   int i, j;
   for (i = 1; i < size; i++)
   {
      int v = array[i];
      j = i - 1;
      while (j >= 0 && array[j] > v)
      {
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = v;
      printArray(array, size, i);
   }
}