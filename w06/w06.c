/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W05
 * 
 * Solution for the restricted Tower of Hanoi problem.
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

void printHanoi(int disks, char from, char temp, char to);

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Enter the number of disks to solve.\n");
      return 0;
   }

   printHanoi(atoi(argv[1]), 'A', 'B', 'C');

   return 0;
}

// Displays each step of the solution for the Tower of Hanoi.
void printHanoi(int disks, char from, char temp, char to)
{
   if (disks == 1)
   {
      printf("Move %c TO %c\n", from, temp);
      printf("Move %c TO %c\n", temp, to);
      return;
   }

   printHanoi(disks - 1, from, temp, to);
   printf("Move %c TO %c\n", from, temp);
   printHanoi(disks - 1, to, temp, from);
   printf("Move %c TO %c\n", temp, to);
   printHanoi(disks - 1, from, temp, to);
}