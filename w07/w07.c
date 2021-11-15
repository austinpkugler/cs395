/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W07
 * 
 * Cyclic Tower of Hanoi
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

void hanoiMoveOne(int disks, char from, char to, char temp);
void hanoiMoveTwo(int disks, char from, char to, char temp);

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Enter the number of disks to solve.\n");
      return 0;
   }

   hanoiMoveTwo(atoi(argv[1]), 'A', 'B', 'C');

   return 0;
}

// Moves a disk one space to the destination.
void hanoiMoveOne(int disks, char from, char to, char temp)
{
   if (disks == 1)
   {
      printf("MOVE %c TO %c\n", from, to);
   }
   else
   {
      hanoiMoveTwo(disks - 1, from, to, temp);
      printf("MOVE %c TO %c\n", from, to);
      hanoiMoveTwo(disks - 1, temp, from, to);
   }
}

// Moves a disk two spaces to the destination.
void hanoiMoveTwo(int disks, char from, char to, char temp)
{
   if (disks == 1)
   {
      printf("MOVE %c TO %c\n", from, to);
      printf("MOVE %c TO %c\n", to, temp);
   }
   else
   {
      hanoiMoveTwo(disks - 1, from, to, temp);
      printf("MOVE %c TO %c\n", from, to);
      hanoiMoveOne(disks - 1, temp, from, to);
      printf("MOVE %c TO %c\n", to, temp);
      hanoiMoveTwo(disks - 1, from, to, temp);
   }
}