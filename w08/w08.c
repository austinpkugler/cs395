/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W08
 *
 * Brute force search for matches in a string.
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc != 3)
   {
      printf("Enter the pattern to match and then a string.\n");
      return 0;
   }

   size_t m = strlen(argv[1]); // pattern length
   size_t n = strlen(argv[2]); // text length

   int positions[200];

   printf("Matches found at locations: ");

   int i, j;
   int count = 0;
   for (i = 0; i < n - m + 1; i++)
   {
      j = 0;
      while (j < m && argv[1][j] == argv[2][i + j])
      {
         j++;
      }
      if (j == m)
      {
         positions[count] = i;
         positions[count + 1] = '\0';
         count++;
      }
   }

   printf("Matches found at locations: ");
   for (i = 0; i < count; i++)
   {
      printf("%d", positions[i]);
      if (i < count - 1)
      {
         printf(" ");
      }
   }
   printf("\n");

   return 0;
}
