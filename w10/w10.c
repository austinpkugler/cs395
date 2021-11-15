/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W10
 *
 * Quicksort with Hoare's Partitioning
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <unistd.h>

void quicksort(int array[], int left, int right, int size);
int hoarePartition(int array[], int left, int right);
void printArray(int array[], int left, int right, int size);
void swap(int *a, int *b);

// Sorts an array using the quicksort algorithm.
void quicksort(int array[], int left, int right, int size)
{
   int split;
   if (left < right)
   {
      split = hoarePartition(array, left, right);
      quicksort(array, left, split - 1, size);
      quicksort(array, split + 1, right, size);
      printArray(array, left, right, size);
   }
}

// Partitions an array using Hoare's algorithm.
int hoarePartition(int array[], int left, int right)
{
   int i, j, initialLeft;
   initialLeft = array[left];
   i = left;
   j = right + 1;

   do
   {
      do
      {
         i++;
      } while (array[i] < initialLeft);
      do
      {
         j--;
      } while (array[j] > initialLeft);

      swap(&array[j], &array[i]);
   } while (i < j);

   swap(&array[j], &array[i]);
   swap(&array[j], &array[left]);

   return j;
}

// Prints the elements of an array.
void printArray(int array[], int left, int right, int size)
{
   int i;
   for (i = 0; i < size; i++)
   {
      if (i == left)
      {
         printf("[");
      }
      printf("%d", array[i]);
      if (i == right)
      {
         printf("]");
      }
      printf(" ");
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

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("Enter integer elements of an array separated by spaces.\n");
      return 0;
   }

   int size = argc - 1;
   int array[size];
   int i;
   for (i = 1; i < argc; i++)
   {
      array[i - 1] = atoi(argv[i]);
   }

   quicksort(array, 0, size - 1, size);
   printArray(array, 0, size - 1, size);

   return 0;
}