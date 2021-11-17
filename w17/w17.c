/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W17
 *
 * Modified Robot Coin Collecting
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int robotCoinCollection(int rowSize, int colSize, int map[rowSize][colSize]);
void printTable(int rowSize, int colSize, int map[rowSize][colSize]);

// Accepts command line arguments as elements of an array.
int main(int argc, char *argv[])
{
   if (argc < 4)
   {
      printf("Insufficient arguments.\n");
      return 0;
   }

   int rowSize = atoi(argv[1]);
   int colSize = atoi(argv[2]);
   int map[rowSize][colSize];

   // Input table
   int i, j;
   for (i = 0; i < rowSize; i++)
   {
      for (j = 0; j < colSize; j++)
      {
         if (strcmp(argv[i * colSize + j + 3], "X") == 0)
         {
            map[i][j] = -1;
         }
         else
         {
            map[i][j] = atoi(argv[i * colSize + j + 3]);
         }
      }
   }

   printf("Board Inputed:\n");
   printTable(rowSize, colSize, map);

   // Coin collection table
   int optimalPath = robotCoinCollection(rowSize, colSize, map);
   printf("The optimal path with this board is: %d\n", optimalPath);

   return 0;
}

// Creates and prints the coin collection table.
int robotCoinCollection(int rowSize, int colSize, int map[rowSize][colSize])
{
   int navTable[rowSize][colSize];
   navTable[0][0] = map[0][0];

   int i, j;

   // Do rows
   for (i = 1; i < rowSize; i++)
   {
      // Current position is a wall
      if (map[i][0] == -1)
      {
         for (i = i; i < colSize; i++)
         {
            navTable[i][0] = 0;
            printf("(%d, %d) set to 0\n", i, 0);
         }
      }
      else
      {
         navTable[i][0] = navTable[i - 1][0] + map[i][0];
      }
   }

   // Do columns
   for (j = 1; j < colSize; j++)
   {
      // Current position is a wall
      if (map[0][j] == -1)
      {
         for (j = j; j < colSize; j++)
         {
            navTable[0][j] = 0;
            printf("(%d, %d) set to 0\n", 0, j);
         }
      }
      else
      {
         navTable[0][j] = navTable[0][j - 1] + map[0][j];
      }
   }

   // Navigate entire map
   for (i = 1; i < rowSize; i++)
   {
      for (j = 1; j < colSize; j++)
      {
         // Current position is a wall
         if (map[i][j] == -1)
         {
            navTable[i][j] = 0;
            printf("(%d, %d) set to 0\n", i, j);
         }
         else
         {
            if (navTable[i - 1][j] > navTable[i][j - 1])
            {
               navTable[i][j] = navTable[i - 1][j] + map[i][j];
            }
            else
            {
               navTable[i][j] = navTable[i][j - 1] + map[i][j];
            }
         }
      }
   }

   // Display coin collecting table
   printf("Coin Collecting Table:\n");
   printTable(rowSize, colSize, navTable);

   return navTable[rowSize - 1][colSize - 1];
}

// Displays a passed table.
void printTable(int rowSize, int colSize, int map[rowSize][colSize])
{
   int i, j;
   for (i = 0; i < rowSize; i++)
   {
      for (j = 0; j < colSize; j++)
      {
         if (map[i][j] == -1)
         {
            printf("%c\t", 'X');
         }
         else
         {
            printf("%d\t", map[i][j]);
         }
      }
      printf("\n");
   }
   printf("\n");
}
