/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W05
 *
 * Tower of Hanoi
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

void printHanoi(int disks, char from, char to, char temp);

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Enter the number of disks to solve.\n");
      return 0;
   }

   printHanoi(atoi(argv[1]), 'A', 'C', 'B');

   return 0;
}

// Displays each step of the solution for the tower of Hanoi.
void printHanoi(int disks, char from, char to, char temp)
{
   // n-1 disks A->B
   // Last A disk A->C
   // n-1 disks B->C
   if (disks == 1)
   {
      printf("Move %c TO %c\n", from, to);
      return;
   }

   printHanoi(disks - 1, from, temp, to);
   printf("Move %c TO %c\n", from, to);
   printHanoi(disks - 1, temp, to, from);
}
